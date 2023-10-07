#include <iostream>
#include <windows.h>
using namespace std;

/*
File type code:
2 --> documents
3 --> audio
4 --> image
5 --> video
6 --> apps
7 --> torrent
*/

void movefile(string oldpath, string newpath)
{
    try
    {
        rename(oldpath.c_str(), newpath.c_str());
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return;
}

void sortfile(int filetype, string filename, string parentDirPath)
{
    string foldername;
    string oldname;
    string newname;

    switch (filetype)
    {
    case 2:
        // Documents
        foldername = "Documents";
        // Create a directory
        CreateDirectoryA((parentDirPath + foldername).c_str(), NULL);

        oldname = parentDirPath + filename;
        newname = parentDirPath + foldername + "\\" + filename;

        // Move the file
        movefile(oldname, newname);
        break;

    case 3:
        // Documents
        foldername = "Audio";
        // Create a directory
        CreateDirectoryA((parentDirPath + foldername).c_str(), NULL);

        oldname = parentDirPath + filename;
        newname = parentDirPath + foldername + "\\" + filename;

        // Move the file
        movefile(oldname, newname);
        break;

    case 4:
        // Documents
        foldername = "Images";
        // Create a directory
        CreateDirectoryA((parentDirPath + foldername).c_str(), NULL);

        oldname = parentDirPath + filename;
        newname = parentDirPath + foldername + "\\" + filename;

        // Move the file
        movefile(oldname, newname);
        break;

    case 5:
        // Documents
        foldername = "Videos";
        // Create a directory
        CreateDirectoryA((parentDirPath + foldername).c_str(), NULL);

        oldname = parentDirPath + filename;
        newname = parentDirPath + foldername + "\\" + filename;

        // Move the file
        movefile(oldname, newname);
        break;

    case 6:
        // Documents
        foldername = "Apps";
        // Create a directory
        CreateDirectoryA((parentDirPath + foldername).c_str(), NULL);

        oldname = parentDirPath + filename;
        newname = parentDirPath + foldername + "\\" + filename;

        // Move the file
        movefile(oldname, newname);
        break;

    case 7:
        // Documents
        foldername = "Torrents";
        // Create a directory
        CreateDirectoryA((parentDirPath + foldername).c_str(), NULL);

        oldname = parentDirPath + filename;
        newname = parentDirPath + foldername + "\\" + filename;

        // Move the file
        movefile(oldname, newname);
        break;

    case 8:
        // Documents
        foldername = "Shortcuts";
        // Create a directory
        CreateDirectoryA((parentDirPath + foldername).c_str(), NULL);

        oldname = parentDirPath + filename;
        newname = parentDirPath + foldername + "\\" + filename;

        // Move the file
        movefile(oldname, newname);
        break;

    default:
        break;
    }

    // Print a success message
    cout << "File sorted successfully" << endl
         << endl;

    return;
}