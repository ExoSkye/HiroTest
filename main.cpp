#include <nall.hpp>
#include <hiro.hpp>
#include "main.hpp"

using namespace nall;

namespace Instances {
    Instance<ProgramWindow> program_inst;
}

ProgramWindow& programWindow = Instances::program_inst();

#include <nall/main.hpp>
auto nall::main(Arguments arguments) -> void {
    Application::setName("HiroTest");
    Instances::program_inst.construct();
    Application::run();
    Instances::program_inst.destruct();
}

Page2::Page2() {
    setCollapsible();
    setVisible(false);

    header.setText("A second page!");
}

Home::Home() {
    setCollapsible();
    setVisible(false);

    header.setText("Hiro Test").setFont(Font().setSize(16).setBold());

    aboutButton.setText("About").onActivate([&] {
        AboutDialog()
        .setName("Hiro Test")
        .setDescription("A simple test application that demonstrates hiro and nall")
        .setVersion("1.0")
        .show();
    });
}

ProgramWindow::ProgramWindow() {
    onClose(&Application::quit);
    layout.setPadding(5_sx, 5_sy);
    panelList.onChange([&] { panelChange(); });
    panelList.append(ListViewItem().setText("Home"));
    panelList.append(ListViewItem().setText("Page 2"));

    panelList.item(0).setSelected();
    panelList.doChange();

    panelContainer.append(home, Size{~0, 0});
    panelContainer.append(page2, Size{~0, 0});

    setTitle("Hiro Test");
    setSize({640_sx, 360_sy});
    setAlignment(Alignment::Center);

    setVisible();
}

void ProgramWindow::panelChange() {
    home->setVisible(false);
    page2->setVisible(false);
    if (auto item = panelList.selected()) {
        switch (item.offset()) {
            case 0:
                home->setVisible(true);
                break;

            case 1:
                page2->setVisible(true);
                break;

            default:
                home->setVisible(true);

        }
    }

    panelContainer.resize();
}
