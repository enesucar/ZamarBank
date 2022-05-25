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
            return "Para �ekme";
        case TransactionType::Deposit:
            return "Para Yat�rma";
        case TransactionType::Transfer:
            return "Para Transferi (EFT)";
        default:
            return "";
    }
}
