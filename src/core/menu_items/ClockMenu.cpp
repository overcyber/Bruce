#include "ClockMenu.h"
#include "core/display.h"
#include "core/settings.h"

void ClockMenu::optionsMenu() {
    runClockLoop();
}
void ClockMenu::drawIconImg() {
    if(bruceConfig.theme.clock) {
        FS* fs = nullptr;
        if(bruceConfig.theme.fs == 1) fs=&LittleFS;
        else if (bruceConfig.theme.fs == 2) fs=&SD;
        drawImg(*fs, bruceConfig.getThemeItemImg(bruceConfig.theme.paths.clock), 0, imgCenterY, true);
    }
}
void ClockMenu::drawIcon(float scale) {
    clearIconArea();
    int radius = scale * 30;
    int pointerSize = scale * 15;

    // Case
    tft.drawArc(
        iconCenterX,
        iconCenterY,
        1.1*radius, radius,
        0, 360,
        bruceConfig.priColor,
        bruceConfig.bgColor
    );

    // Pivot center
    tft.fillCircle(iconCenterX, iconCenterY, radius/10, bruceConfig.priColor);

    // Hours & minutes
    tft.drawLine(
        iconCenterX, iconCenterY,
        iconCenterX - 2*pointerSize/3, iconCenterY - 2*pointerSize/3,
        bruceConfig.priColor
    );
    tft.drawLine(
        iconCenterX, iconCenterY,
        iconCenterX + pointerSize, iconCenterY - pointerSize,
        bruceConfig.priColor
    );
}