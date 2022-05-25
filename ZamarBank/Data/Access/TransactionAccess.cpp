#include "TransactionAccess.h"

int TransactionAccess::Add(TransactionViewModel model)
{
	string createDate = DateTimeHelper::GetCurrentDateTime();
	string accountBalanceString = to_string(model.Balance);
	accountBalanceString = StringHelper::ReplaceAll(accountBalanceString, ",", ".");
	string sql = "";

	if (model.Type == TransactionType::Withdraw)
	{
		AccountAccess::UpdateBalance(model.FromAccountID, model.Balance * - 1);
		sql += "Insert Into \"main\".\"Transaction\" (FromAccountID, Type, Balance, Description, CreateDate) ";
		sql += "Values (" + to_string(model.FromAccountID) + ", " + to_string((int)model.Type) + ", " + accountBalanceString + ", '" + model.Description + "', '" + createDate + "');";
	}
	else if (model.Type == TransactionType::Deposit)
	{
		AccountAccess::UpdateBalance(model.FromAccountID, model.Balance);
		sql += "Insert Into \"main\".\"Transaction\" (FromAccountID, Type, Balance, Description, CreateDate) ";
		sql += "Values (" + to_string(model.FromAccountID) + ", " + to_string((int)model.Type) + ", " + accountBalanceString + ", '" + model.Description + "', '" + createDate + "');";
	}
	else if (model.Type == TransactionType::Transfer)
	{
		Account fromAccount = AccountAccess::GetByID(model.FromAccountID);
		Account toAccount = AccountAccess::GetByIBAN(model.ToAccountIBAN);

		if (fromAccount.Type != toAccount.Type) // Hesap tipleri ayný olmalý.
		{
			return 0;
		}
		if (toAccount.ID == 0) // Para aktarýlacak hesap bulunamadý.
		{
			return 0;
		}

		AccountAccess::UpdateBalance(model.FromAccountID, model.Balance * -1);
		AccountAccess::UpdateBalance(toAccount.ID, model.Balance);

		sql += "Insert Into \"main\".\"Transaction\" (FromAccountID, ToAccountID, Type, Balance, Description, CreateDate) ";
		sql += "Values (" + to_string(model.FromAccountID) + ", " + to_string(toAccount.ID) + ", " + to_string((int)model.Type) + ", " + accountBalanceString + ", '" + model.Description + "', '" + createDate + "');";
	} 

	int result = Database::ExecuteSQL(sql);
	return result;
}
