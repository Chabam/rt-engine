# RT engine (WIP)
## Goals
* Open obj files for loading a scene
  * No editing of the scene, only moving the camera
* Have a rasterizer to display it by default
* Image rendering
* Multi-threaded

## How to build
```bash
$ python setup.py
```
to generate the cmake files. By default it generates a Visual Studio solution under `_project`.
Use Visual Studio from there (or the generator you want).

## Libs
* GLEW
* GLWF
* GLM
## Credits
* Template project by [ArthurSonzogni](https://github.com/ArthurSonzogni)