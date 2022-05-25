#pragma once

enum class AccountType
{
	TL_Hesabi,
	Dolar_Hesabi,
	Euro_Hesabi,
	Altin_Hesabi
};

inline const char* AccountTypeToString(AccountType type)
{
    switch (type)
    {
        case AccountType::TL_Hesabi:  
            return "TL";
        case AccountType::Dolar_Hesabi:   
            return "Dolar";
        case AccountType::Euro_Hesabi:
            return "Euro";
        case AccountType::Altin_Hesabi:
            return "Altın";
        default:     
           return "";
    }
}