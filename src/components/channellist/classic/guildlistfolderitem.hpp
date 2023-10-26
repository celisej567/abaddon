#pragma once
#include <gtkmm/box.h>
#include <gtkmm/eventbox.h>
#include <gtkmm/image.h>
#include <gtkmm/revealer.h>

#include "guildlistguilditem.hpp"

class GuildListGuildItem;

class GuildListFolderItem : public Gtk::VBox {
public:
    GuildListFolderItem();

    void AddGuildWidget(GuildListGuildItem *widget);

private:
    Gtk::EventBox m_ev;
    Gtk::Image m_image;
    Gtk::Revealer m_revealer;
    Gtk::VBox m_box;
};
