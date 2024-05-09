#pragma once

class Entity
{
   private:
   int m_id;
   std::string m_name;

   public:
    Entity(){}
    Entity(int id,std::string name) :  m_id(id), m_name(name) {} 

    int getId()
    {
      return m_id;
    }

    std::string getName()
    {
      return m_name;
    }
};

