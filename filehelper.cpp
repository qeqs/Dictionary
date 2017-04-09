#include "filehelper.h"
#include <windows.h>


FileHelper::FileHelper()
{

}

list<string>* FileHelper::find_dictionaries()
{
    if(CreateDirectory(LPCWSTR(L"\dict"),NULL)  ||
            ERROR_ALREADY_EXISTS == GetLastError()){
        return nullptr;
    }

        list<string>* files = new list<string>();
        WIN32_FIND_DATA file;
        HANDLE search_handle=FindFirstFile(L".\\dict\\*",&file);
        if (search_handle)
        {
            do
            {
                wstring wstr(file.cFileName);
                std::string s( wstr.begin(), wstr.end() );
                if(s.size()>4&&s.substr(s.size()-3,3)==string("xml")){
                    files->push_back(s);
                }
            }
            while(FindNextFile(search_handle,&file));

            CloseHandle(search_handle);

        }
    return files;
}
