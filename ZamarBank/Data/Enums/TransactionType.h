#pragma once

enum class TransactionType
{
	Withdraw,
	Deposit,
	Transfer
};

inline const char* TransactionTypeToString(TransactionType type)
{
    switch (type)
    {
        case TransactionType::Withdraw:
            return "Para Çekme";
        case TransactionType::Deposit:
            return "Para Yatýrma";
        case TransactionType::Transfer:
            return "Para Transferi (EFT)";
        default:
            return "";
    }
}
