/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** IScene
*/



#pragma once

class SceneManager;

class IScene {
public:
    ~IScene() = default;

    virtual void loadScene(SceneManager *manager, void *data) = 0;
    virtual void unloadScene(SceneManager *manager, void *data) = 0;
    virtual void run(SceneManager *manager, void *data) = 0;
};
