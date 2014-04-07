/*
 * Copyright (C) 2014  Maxim Noah Khailo
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef FIRESTR_APP_CHAT_H
#define FIRESTR_APP_CHAT_H

#ifndef Q_MOC_RUN
#include "gui/list.hpp"
#include "gui/mail_service.hpp"
#include "gui/message.hpp"
#include "conversation/conversation_service.hpp"
#include "message/mailbox.hpp"
#include "messages/sender.hpp"
#endif

#include <QObject>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>

#include <string>

namespace fire
{
    namespace gui
    {
        namespace app
        {
            class chat_app : public message
            {
                Q_OBJECT

                public:
                    chat_app(
                            conversation::conversation_service_ptr,
                            conversation::conversation_ptr);
                    chat_app(
                            const std::string& id, 
                            conversation::conversation_service_ptr,
                            conversation::conversation_ptr);
                    ~chat_app();

                public:
                    const std::string& id();
                    const std::string& type();
                    fire::message::mailbox_ptr mail();

                public slots:
                    void send_message();
                    void check_mail(fire::message::message);

                private:
                    void init();

                private:
                    std::string _id;
                    mail_service* _mail_service;
                    conversation::conversation_service_ptr _conversation_service;
                    conversation::conversation_ptr _conversation;
                    fire::message::mailbox_ptr _mail;
                    messages::sender_ptr _sender;

                    gui::list* _messages;
                    QLineEdit* _message;
                    QPushButton* _send;
            };
            extern const std::string CHAT;

        }
    }
}

#endif

