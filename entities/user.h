/**
 * user.h define the User
 * 
 */
#include <string>
#include "entity.h"
namespace entities
{

class User : public Entity
{
public:
    User()=default;
    ~User()=default;
    User(const User&) = default;
    User(User&&) = default;
    User& operator=(const User&) = default;
    User& operator=(User&&) = default;

    //TODO: copy, move, assignement

public:

    void set_email(const std::string& email){
        m_email = email;
    }
    std::string get_email() const{return m_email;}

    void set_name(const std::string& name){
        m_name = name;
    }
    std::string get_name() const{return m_name;}

    void set_password(const std::string& password){
        m_password = password;
    }
    std::string get_password() const{return m_password;}

    void set_title(const std::string& title){
        m_title = title;
    }
    std::string get_title() const{return m_title;}

    std::string to_string(const std::string& delimiter) const override{
        std::string result;
        result += m_email;
        result += delimiter;
        result += m_name;
        result += delimiter;
        result += m_password;
        result += delimiter;
        result += m_title;
        result += "\n";
       
        return result;

    }



private:
    std::string m_email;
    std::string m_name;
    std::string m_password;
    std::string m_title;
};
}