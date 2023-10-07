#include <iostream>
#include <windows.h>
#include "./lib/filetype.cpp"
#include "./lib/sortfile.cpp"
#include <string>
using namespace std;

int main()
{
    WIN32_FIND_DATAA fileData;
    HANDLE dir;

    string dirpath;

    cout << "Enter the full path of the directory you want to organize: " << endl;
    cin >> dirpath;

    dirpath = dirpath + "\\"; // Append "\\" after the full dirpath name

    try
    {
        dir = FindFirstFileA((dirpath + "*").c_str(), &fileData);

        if (dir == INVALID_HANDLE_VALUE)
        {
            return 0; // No file in the directory
        }

        do
        {
            const string filename = fileData.cFileName;
            const bool is_directory = (fileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;

            if (filename[0] == '.')
            {
                continue; // Dont return any filename starting with '.'
            }

            if (is_directory)
            {
                continue; // Dont do any operation if current file is a directory
            }
            cout << filename << endl;
            int _filetype = filetype(filename);

            if (_filetype == 0)
            {
                cout << "File format not supported" << endl
                     << endl;
                continue; // File type is not supported for sorting
            }

            sortfile(_filetype, filename, dirpath); // Sort the file

        } while (FindNextFileA(dir, &fileData));

        // Close the dir
        FindClose(dir);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}