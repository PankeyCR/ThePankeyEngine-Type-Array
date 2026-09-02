#pragma once

#include "IP.hpp"
#include "ByteArray.hpp"
#include "move.hpp"

namespace pankey{

	namespace Type{

		namespace Array{

			class Message{
				public:
					Message(){}

					Message(const pankey::Type::Array::IP& a_ip, int a_port, const pankey::Type::Array::ByteArray& a_message)
						: m_ip(a_ip), m_port(a_port), m_message(a_message) {}

					Message(const Message& a_message)
						: m_ip(a_message.m_ip), m_port(a_message.m_port), m_message(a_message.m_message) {}

					Message(Message&& a_message) noexcept
						: m_ip(pankey::Utility::Base::move(a_message.m_ip)), m_port(a_message.m_port), m_message(pankey::Utility::Base::move(a_message.m_message)) {}

					Message& operator=(const Message& a_message){
						m_ip = a_message.m_ip;
						m_port = a_message.m_port;
						m_message = a_message.m_message;
						return *this;
					}

					Message& operator=(Message&& a_message) noexcept {
						m_ip = pankey::Utility::Base::move(a_message.m_ip);
						m_port = a_message.m_port;
						m_message = pankey::Utility::Base::move(a_message.m_message);
						return *this;
					}

					bool operator==(const Message& a_message) const {
						return m_ip == a_message.m_ip && m_port == a_message.m_port && m_message == a_message.m_message;
					}

					bool operator!=(const Message& a_message) const {
						return m_ip != a_message.m_ip || m_port != a_message.m_port || m_message != a_message.m_message;
					}

					bool isEmpty() const {
						return m_message.isEmpty();
					}
				protected:
					pankey::Type::Array::IP m_ip = createIP(0,0,0,0);
					int m_port = 0;
					pankey::Type::Array::ByteArray m_message;
			};

		}

	}

}
