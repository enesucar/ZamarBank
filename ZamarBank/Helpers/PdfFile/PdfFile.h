#pragma once
#pragma warning(disable: 4996)
#include "../../Sources/VulcanWarePDF/pdf.h"

using namespace std;

class PdfFileHelper
{
	public:
		static void CreatePdfFile(vector<string>, string folderName);
	
	private:
		static string GetDesktopPathOfUser();
};