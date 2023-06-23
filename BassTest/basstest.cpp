#include <Windows.h>
#include <iostream>
#include <bass/bass.h>
#pragma comment (lib, "bass.lib")
namespace BASS {
    void SettingMusic() 
    {
        BASS_Init(-1, 44100, 0, 0, 0);
        BASS_SetConfig(5, 460);
        BASS_SetConfig(6, 460);
    }
    void PlayMusic(const char* music_path) {
        HSTREAM str = BASS_StreamCreateFile(false, music_path, 0, 0, 0);
        if (!str) {
            MessageBoxA(0, "Failed To Create Stream File for Music", "BassTest", MB_OK | MB_ICONINFORMATION);
            exit(133);
        }
        BASS_Start();
        BASS_ChannelPlay(str, TRUE); //Playing Channel :D
    }
}
void FlashConsoleBackgroundColor(int cntFlashes, int flashInterval_ms, COLORREF color)
{

    CONSOLE_SCREEN_BUFFER_INFOEX sbInfoEx;
    sbInfoEx.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);

    HANDLE consoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfoEx(consoleOut, &sbInfoEx);

    COLORREF storedBG = sbInfoEx.ColorTable[0];

    for (int i = 0; i < cntFlashes; ++i)
    {
        //-- set BG color
        Sleep(flashInterval_ms);
        sbInfoEx.ColorTable[0] = color;
        SetConsoleScreenBufferInfoEx(consoleOut, &sbInfoEx);
    }
}
int main() {
    printf("[+] Welcome To The BassTest by BrioPlus");
    FlashConsoleBackgroundColor(20, 50, RGB(155, 35, 122));
    printf("\n[+] Trying To Initializating Bass...");
    Sleep(5000);
    BASS::SettingMusic(); //Setting Music :D
    printf("\n[+] Playing Music: Freddie Dredd - Devil's Work(Speed Up)");
    BASS::PlayMusic("FreddieDredd_DevilsWorkSpeedUp.mp3");
    getchar();
    return 0;
}