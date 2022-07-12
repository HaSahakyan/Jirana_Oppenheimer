/**
 * @file project.h
 * 
 */
#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include <vector>
#include "entity.h"
#include "task.h"
#include "user.h"
#include "project.h"



namespace entities{
class Project : public Entity
{
public: 
    Project()=default;
    Project(std::string name) : m_name{name}{}
    Project(const Project&)=default;
    Project(Project&&)=default;
    Project& operator=(const Project&) = default;
    Project& operator=(Project&&) = default;
    ~Project()=default;

public:
    void set_name(std::string name){
        m_name = name;
    }
    std::string name() const{
        return m_name;
    }

    void set_manager(const User& manager){
        m_manager = manager;
    }
    
    User manager() const{
        return m_manager;
    }

    void set_task(const std::vector<Task>& tasks){
        m_tasks =tasks;
    }

    std::vector<Task> task() const{ 
        return m_tasks;

    }

    void add_task(const Task& task){
        m_tasks.push_back(task);
    }

    void remove_task(const Task& task){
        auto begin = m_tasks.begin();
        auto end = m_tasks.end();
        for(; begin!= end; ++begin){
            if(*begin == task){
                m_tasks.erase(begin);
                break;
            }
        }
    }

    private:
        static void counter(){
            m_count ++;
        }

    std::string to_string(const std::string delimiter) const override{
        std::string result;
        result += "Task ";
        result += m_count;
        counter();
        result += m_name;
        result += delimiter;
        result += m_manager.to_string(delimiter);
        result += "\n";
        for(int i{}; i < m_tasks.size(); ++i){
            result += m_tasks[i].to_string(delimiter);
            result += "\n";
        }
        return result;
    }
private:
    std::string m_name;
    User m_manager;
    std::vector<Task> m_tasks;
    int m_count;

};

}









#endif