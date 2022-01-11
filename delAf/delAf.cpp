#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //создание файла
    ofstream file;
    file.open("test.ps1");

    string newArg = "-auto";
    string powershell;
    //запись команд
    powershell = "$list = Get-WinUserLanguageList\n";
    powershell += "$list.Add(\"af\")\n";
    powershell += "Set-WinUserLanguageList $List -Force \n";

    powershell += "$List = Get-WinUserLanguageList\n";
    powershell += "$Index = $List.LanguageTag.IndexOf(\"af\")\n";
    powershell += "$List.RemoveAt($Index) \n";
    powershell += "Set-WinUserLanguageList $List -Force \n";
    file << powershell << endl;
    file.close();
    //выполнение команд
    system("powershell -ExecutionPolicy Bypass -F test.ps1");
    remove("test.ps1");
    std::cout << "Done" << endl;
}