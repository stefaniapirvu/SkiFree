#pragma once

#include <string>
#include <unordered_map>

#include "components/simple_scene.h"
#include "components/transform.h"
#include "lab_m1/Tema3/camera3.h"
#include "components/text_renderer.h"



namespace m1
{
    class Tema3 : public gfxc::SimpleScene
    {
     public:
         Tema3();
        ~Tema3();

        void Init() override;

     private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;
        bool Coliziune(glm::vec3 Point);

        void RenderSimpleMesh(Mesh *mesh, Shader *shader, const glm::mat4 &modelMatrix, Texture2D *texture1 = NULL, Texture2D *texture2 = NULL);
        //Texture2D *CreateRandomTexture(unsigned int width, unsigned int height);

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;
        void RenderScene(float deltaTimeSeconds);
        void RenderText(std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color = glm::vec3(1.0f));

        std::unordered_map<std::string, Texture2D *> mapTextures;
        GLuint randomTextureID;


    protected:

        implemented::Camera3* camera;
        float x, y, z;
        float angle;
        float x_plane, y_plane, z_plane;
        float viteza;
        float camera_x, camera_y, camera_z;
        float prev_z, prev_z2, prev_z_cadou, prev_z2_cadou;
        float prev_z_pietre, prev_z2_pietre, prev_z_stalpi, prev_z2_stalpi;
        float player_size;
        float gift_size;

        std::vector<glm::vec3> aux;
        std::vector<glm::vec3> aux2;

        std::vector<glm::vec3> aux_pietre;
        std::vector<glm::vec3> aux2_pietre;
        std::vector<glm::vec3> aux_stalpi;
        std::vector<glm::vec3> aux2_stalpi;

        std::vector<glm::vec3> pietre;
        std::vector<glm::vec3> stalpi;
        std::vector<glm::vec3> braduti;

        int scor;
        int time;

        

        
    };
}   // namespace m1

