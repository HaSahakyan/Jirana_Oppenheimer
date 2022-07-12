/**
 * To save or load contents from files for entities
 * user, project, and task
 * 
 */
#include <fstream>
#include <../entities/entity.h>

#ifndef CORE_FILE_CONTROLLER_H
#define CORE_FILE_CONTROLLER_H

namespace core{

class FileController{
private:
    static fstream f{"info.txt"};
public:
    FileController()=delete;
    ~FileController()=delete;

    static void saveEntity(const entities::Entity& e){
        
        f << e.to_string(" | ");
    }
    static void load(){}

};

}





#endif // CORE_FILE_CONTROLLER_H