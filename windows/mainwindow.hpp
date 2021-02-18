#pragma once
#include "../components/channels.hpp"
#include "../components/chatwindow.hpp"
#include "../components/memberlist.hpp"
#include <gtkmm.h>

class MainWindow : public Gtk::Window {
public:
    MainWindow();

    void UpdateComponents();
    void UpdateMembers();
    void UpdateChannelListing();
    void UpdateChannelsNewGuild(Snowflake id);
    void UpdateChannelsRemoveGuild(Snowflake id);
    void UpdateChannelsRemoveChannel(Snowflake id);
    void UpdateChannelsUpdateChannel(Snowflake id);
    void UpdateChannelsCreateChannel(Snowflake id);
    void UpdateChannelsUpdateGuild(Snowflake id);
    void UpdateChatWindowContents();
    void UpdateChatActiveChannel(Snowflake id);
    Snowflake GetChatActiveChannel() const;
    void UpdateChatNewMessage(Snowflake id);
    void UpdateChatMessageDeleted(Snowflake id, Snowflake channel_id);
    void UpdateChatMessageUpdated(Snowflake id, Snowflake channel_id);
    void UpdateChatPrependHistory(const std::vector<Snowflake> &msgs);
    void InsertChatInput(std::string text);
    Snowflake GetChatOldestListedMessage();
    void UpdateChatReactionAdd(Snowflake id, const Glib::ustring &param);
    void UpdateChatReactionRemove(Snowflake id, const Glib::ustring &param);

    ChannelList *GetChannelList();
    ChatWindow *GetChatWindow();
    MemberList *GetMemberList();

public:
    typedef sigc::signal<void> type_signal_action_connect;
    typedef sigc::signal<void> type_signal_action_disconnect;
    typedef sigc::signal<void> type_signal_action_set_token;
    typedef sigc::signal<void> type_signal_action_reload_css;
    typedef sigc::signal<void> type_signal_action_join_guild;
    typedef sigc::signal<void> type_signal_action_set_status;
    typedef sigc::signal<void, const GdkEvent *, Snowflake, Snowflake> type_signal_action_show_user_menu;
    typedef sigc::signal<void> type_signal_action_reload_settings;
    typedef sigc::signal<void, Snowflake> type_signal_action_add_recipient; // channel id

    type_signal_action_connect signal_action_connect();
    type_signal_action_disconnect signal_action_disconnect();
    type_signal_action_set_token signal_action_set_token();
    type_signal_action_reload_css signal_action_reload_css();
    type_signal_action_join_guild signal_action_join_guild();
    type_signal_action_set_status signal_action_set_status();
    type_signal_action_show_user_menu signal_action_show_user_menu();
    type_signal_action_reload_settings signal_action_reload_settings();
    type_signal_action_add_recipient signal_action_add_recipient();

protected:
    type_signal_action_connect m_signal_action_connect;
    type_signal_action_disconnect m_signal_action_disconnect;
    type_signal_action_set_token m_signal_action_set_token;
    type_signal_action_reload_css m_signal_action_reload_css;
    type_signal_action_join_guild m_signal_action_join_guild;
    type_signal_action_set_status m_signal_action_set_status;
    type_signal_action_show_user_menu m_signal_action_show_user_menu;
    type_signal_action_reload_settings m_signal_action_reload_settings;
    type_signal_action_add_recipient m_signal_action_add_recipient;

protected:
    Gtk::Box m_main_box;
    Gtk::Box m_content_box;
    Gtk::Paned m_chan_chat_paned;
    Gtk::Paned m_chat_members_paned;

    ChannelList m_channel_list;
    ChatWindow m_chat;
    MemberList m_members;

    Gtk::MenuBar m_menu_bar;
    Gtk::MenuItem m_menu_discord;
    Gtk::Menu m_menu_discord_sub;
    Gtk::MenuItem m_menu_discord_connect;
    Gtk::MenuItem m_menu_discord_disconnect;
    Gtk::MenuItem m_menu_discord_set_token;
    Gtk::MenuItem m_menu_discord_join_guild;
    Gtk::MenuItem m_menu_discord_set_status;
    Gtk::MenuItem m_menu_discord_add_recipient; // move me somewhere else some day
    void OnDiscordSubmenuPopup(const Gdk::Rectangle *flipped_rect, const Gdk::Rectangle *final_rect, bool flipped_x, bool flipped_y);

    Gtk::MenuItem m_menu_file;
    Gtk::Menu m_menu_file_sub;
    Gtk::MenuItem m_menu_file_reload_settings;
    Gtk::MenuItem m_menu_file_reload_css;
    Gtk::MenuItem m_menu_file_clear_cache;
};
