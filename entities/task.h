/**
 * @file task.h
 * 
 */
#include <string>
#include "entity.h"
#include "user.h"

namespace entities
{

class Task : public Entity
{
public:
    Task()=default;
    ~Task()=default;
    Task(const Task&) = default;
    Task(Task&&) = default;
    Task& operator=(const Task&) = default;
    Task& operator=(Task&&) = default;

public:

    void set_name(const std::string& name){
        m_name = name;
    }
    std::string get_name() const{return m_name;}

    void set_deadline(const std::string& deadline){
        m_deadline = deadline;
    }
    std::string get_deadline() const{return m_deadline;}

    void set_assigned(const User& assigned){
        m_assigned = assigned;
    }
    User assigned() const{return m_assigned;}

    std::string to_string(const std::string& delimiter) const override{
        std::string result;
        result += m_name;
        result += delimiter;
        result += m_deadline;
        result += delimiter;
        result += m_assigned.to_string(delimiter);
        result += delimiter;
        result += m_state;
        result += "\n";
       
        return result;

    }



private:
    std::string m_name;
    std::string m_deadline;
    User m_assigned;
    std::string m_state;
};
}