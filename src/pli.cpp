#include "pli.h"

Pli::Pli()
{}

Pli::~Pli()
{}

int Pli::register_pli_information(const POLICEMAN &pli_man)
{
    std::string sql = "insert into POLICE_message VALUES ('"+pli_man.Name+"','"+pli_man.Number+"','"+pli_man.Sex+"','"+pli_man.Age+"','"+pli_man.Location+"','"+pli_man.Tel+"')";
    int ret = sql_handle.sql_insert(sql);
    if (ret != 0)
    {
        return -1;
    }
    return 0;
}

bool Pli::test_sign_in_information(const COUNT &cou)
{
    std::string sql = "select passwd form POLICE_message where ID='"+cou.ID+"'";
    sql_handle.sql_select(sql);
    std::string passwd;
    while(sql_handle.resultSet->next())
    {
        try{
            passwd = sql_handle.resultSet->getString(2);
        }
        catch (std::exception e)
        {
            std::cout<<e.what();
        }
    }
    if (passwd.compare(cou.passwd) == 0)
    {
       // root["status"] = "YES";
        return true;
    }
    else
    {
        return false;
       // root["status"] = "NO";
    }
   // std::string out = root.toStyledString();
   // send(sock_client,out.c_str(),strlen(out.c_str()),0);
}

int Pli::get_gps_information()
{}

int Pli::get_person_information()
{}

int Pli::get_car_information()
{}

int Pli::get_worning_information()
{}

int Pli::begin_dealWith_worning_information(POLICEMAN &police,CAR &car,PERSON &per)
{
    std::string sql = "select * from POLICEMAN_message where Number="+police.Number+"";
    sql_handle.sql_select(sql);
    while(sql_handle.resultSet->next())
    {
        try
        {
            police.Name = sql_handle.resultSet->getString(1);
            police.Sex = sql_handle.resultSet->getString(3);
            police.Age = sql_handle.resultSet->getString(4);
            police.Location = sql_handle.resultSet->getString(5);
            police.Tel = sql_handle.resultSet->getString(6);

        }
        catch (std::exception e)
        {
            std::cout<<e.what();
        }
    }
    car.Status = "FOUNDING";
    //push 
    //car number person ID  police man information
}

int Pli::end_dealWith_worning_information(PERSON &per,CAR &car)
{
    //push
    //car number per ID 
}

