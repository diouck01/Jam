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
    scene->loadScene(this, NULL);
}

void SceneManager::display(void *data)
{
    std::map<std::string, IScene*>::iterator end = _sceneList.find(_previousScene);
    if (end != _sceneList.end())
        _sceneList.find(_previousScene)->second->unloadScene(this, data);
    IScene *it = _sceneList.find(_currentScene)->second;
    it->loadScene(NULL, NULL);
    it->run(this, data);
}

void SceneManager::changeMenu(std::string sceneName)
{
    _previousScene = _currentScene;
    _currentScene = sceneName;
}