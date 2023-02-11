/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** SceneManager
*/

#include "SceneManager.hpp"

SceneManager::SceneManager()
{
    _currentScene = "MainMenu";
}

SceneManager::~SceneManager()
{
}

void SceneManager::addMenu(std::string menuName, IScene *scene)
{
    _sceneList.insert({menuName, scene});
}

void SceneManager::display(void *data)
{
    static bool tmp = false;
    IScene *it = _sceneList.find(_currentScene)->second;
    if (tmp == false) {
        std::map<std::string, IScene*>::iterator end = _sceneList.find(_previousScene);
        if (end != _sceneList.end())
            _sceneList.find(_previousScene)->second->unloadScene(this, data);
        it->loadScene(NULL, NULL);
        tmp = true;
    }
    it->run(this, data);
}

void SceneManager::changeMenu(std::string sceneName)
{
    _previousScene = _currentScene;
    _currentScene = sceneName;
}