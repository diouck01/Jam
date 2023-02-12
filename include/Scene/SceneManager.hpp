/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** MenuManager
*/

#pragma once

#include <map>
#include <string>
#include <iostream>

#include "IScene.hpp"

class SceneManager {
public:
    SceneManager();
    ~SceneManager();

    void addMenu(std::string menuName, IScene *scene);
    void display(void *data);
    void changeMenu(std::string sceneName);

protected:
    std::string _currentScene = "None";
    std::string _previousScene = "None";
    std::map<std::string, IScene*> _sceneList;
};
