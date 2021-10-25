/*
 * Xournal++
 *
 * The Main window
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include <memory>
#include <string>
#include <vector>

#include <gtk/gtk.h>


class Settings;
class ToolbarData;
class ToolMenuHandler;
class MenuSelectToolbarData;
class MainWindow;

class MainWindowToolbarMenu final {
public:
    MainWindowToolbarMenu(MainWindow* win);
    ~MainWindowToolbarMenu();

public:
    // void updateToolbarMenu(GtkMenuShell* menubar, Settings* settings, ToolMenuHandler* toolbar);
    ToolbarData* getSelectedToolbar();
    void setTmpDisabled(bool disabled);

private:
    void freeToolMenu();
    void selectToolbar(Settings* settings, ToolMenuHandler* toolbar);
    //  void removeOldElements(GtkMenuShell* menubar);
    // void addToolbarMenuEntry(ToolbarData* d, GtkMenuShell* menubar, int& menuPos);
    // void menuClicked(GtkCheckMenuItem* menuitem, MenuSelectToolbarData* data);

    // static void tbSelectMenuitemActivated(GtkCheckMenuItem* menuitem, MenuSelectToolbarData* data);

private:
    MainWindow* win = nullptr;

    std::vector<GtkWidget*> menuitems;
    std::vector<std::unique_ptr<MenuSelectToolbarData>> toolbarMenuData;

    ToolbarData* selectedToolbar = nullptr;
    bool inPredefinedSection = false;
};
