#include <iostream>
#include "./split.cpp"
using namespace std;

/*
File type code:
2 --> documents
3 --> audio
4 --> image
5 --> video
6 --> apps
7 --> torrent
8 --> shortcuts
9 --> archives
10 --> json
*/

bool belongsToDoc(string docarr[], string ext, int docarrsize)
{
    int i = 0;
    while (i < docarrsize)
    {
        if (docarr[i] == ext)
        {
            return true;
        }
        i++;
    }

    return false;
}

bool belongsToAudio(string arr[], string ext, int arrsize)
{
    int i = 0;
    while (i < arrsize)
    {
        if (arr[i] == ext)
        {
            return true;
        }
        i++;
    }

    return false;
}

bool belongsToImage(string arr[], string ext, int arrsize)
{
    int i = 0;
    while (i < arrsize)
    {
        if (arr[i] == ext)
        {
            return true;
        }
        i++;
    }

    return false;
}

bool belongsToTorrent(string arr[], string ext, int arrsize)
{
    int i = 0;
    while (i < arrsize)
    {
        if (arr[i] == ext)
        {
            return true;
        }
        i++;
    }

    return false;
}

bool belongsToApp(string arr[], string ext, int arrsize)
{
    int i = 0;
    while (i < arrsize)
    {
        if (arr[i] == ext)
        {
            return true;
        }
        i++;
    }

    return false;
}

bool belongsToVideo(string arr[], string ext, int arrsize)
{
    int i = 0;
    while (i < arrsize)
    {
        if (arr[i] == ext)
        {
            return true;
        }
        i++;
    }

    return false;
}

bool belongsToShortcut(string arr[], string ext, int arrsize)
{
    int i = 0;
    while (i < arrsize)
    {
        if (arr[i] == ext)
        {
            return true;
        }
        i++;
    }

    return false;
}

bool belongsToArchive(string arr[], string ext, int arrsize)
{
    int i = 0;
    while (i < arrsize)
    {
        if (arr[i] == ext)
        {
            return true;
        }
        i++;
    }

    return false;
}

bool belongsToJson(string arr[], string ext, int arrsize)
{
    int i = 0;
    while (i < arrsize)
    {
        if (arr[i] == ext)
        {
            return true;
        }
        i++;
    }

    return false;
}

// Return the group code to which the file belongs
int filegroup(string extension)
{
    string docExt[7] = {"pdf", "doc", "txt", "xls", "ppt", "docx", "xlsx"};
    string imgExt[7] = {"jpg", "jpeg", "png", "svg", "xar", "ani", "webp"};
    string audioExt[7] = {"mp3", "wav"};
    string videoExt[7] = {"mp4", "ogg", "flm"};
    string torrentExt[1] = {"torrent"};
    string appExt[7] = {"exe", "bat", "bash", "sh", "msi"};
    string shortcutExt[1] = {"lnk"};
    string archiveExt[7] = {"zip", "tar", "zst", "rar"};
    string jsonExt[1] = {"json"};

    if (belongsToDoc(docExt, extension, 7))
    {
        return 2;
    }
    else if (belongsToAudio(audioExt, extension, 7))
    {
        return 3;
    }
    else if (belongsToImage(imgExt, extension, 7))
    {
        return 4;
    }
    else if (belongsToVideo(videoExt, extension, 7))
    {
        return 5;
    }
    else if (belongsToApp(appExt, extension, 7))
    {
        return 6;
    }
    else if (belongsToTorrent(torrentExt, extension, 1))
    {
        return 7;
    }
    else if (belongsToShortcut(shortcutExt, extension, 1))
    {
        return 8;
    }
    else if (belongsToArchive(archiveExt, extension, 7))
    {
        return 9;
    }
    else if (belongsToJson(jsonExt, extension, 1))
    {
        return 10;
    }
    return 0;
}

int filetype(string filename)
{
    int filetype = 0;
    int size = filename.size();
    string splits[100];

    int splits_arr_length = split(filename, '.', splits);

    string extension = splits[splits_arr_length - 1];

    filetype = filegroup(extension);

    return filetype;
}