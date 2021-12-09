#pragma once

#include <nall.hpp>
using namespace nall;

#include <hiro.hpp>
using namespace hiro;

struct Page2 : VerticalLayout {
    Page2();

protected:
    Label header{this, Size{~0, 0}};
};

struct Home : VerticalLayout {
    Home();

protected:
    Label header{this, Size{~0, 0}};
    Button aboutButton{this, Size{80_sx, 0}};
};

struct ProgramWindow : Window {
    ProgramWindow();
    void panelChange();

    Home home;
    Page2 page2;

    HorizontalLayout layout{this};
    ListView panelList{&layout, Size{150_sx, ~0}};
    VerticalLayout panelContainer{&layout, Size{~0, ~0}};
};