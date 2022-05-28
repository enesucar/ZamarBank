#include "PdfFile.h"

void PdfFileHelper::CreatePdfFile(vector<string> text, string folderName)
{
	PDF pdf;
	pdf.setFont(PDF::HELVETICA, 12);

    static const int FONTSIZE = 14;
    static const int MARGIN = 36;
    static const int YSTART = 750;

    int y = YSTART;
    bool showLine = false;

    bool needSetFont = true;

    for (int i = 0, n = text.size(); i < n; i++)
    {
        if (needSetFont)
        {
            pdf.setFont(PDF::COURIER, FONTSIZE);
            needSetFont = false;
        }

        pdf.showTextXY(text[i], MARGIN, y);
        y -= FONTSIZE;

        if (y <= MARGIN)
        {
            pdf.newPage();
            needSetFont = true;
            y = YSTART;    
        }
    }

    string errMessage;
    pdf.writeToFile(GetDesktopPathOfUser() + "\\" + folderName, errMessage);
}

string PdfFileHelper::GetDesktopPathOfUser()
{
    char* userprofile = std::getenv("USERPROFILE");
    if (userprofile)
    {
        return std::string(userprofile) + "\\Desktop";
    }
    return "";
}
