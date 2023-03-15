#include "lab_m1/Tema3/Tema3.h"
#include "components/text_renderer.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;
using namespace m1;


struct cadou {
    
    glm::vec3 poz;
    bool ok;
};

vector<cadou> cadouri;
vector<cadou> cadou_aux;
vector<cadou> cadou_aux2;

Tema3::Tema3()
{
}


Tema3::~Tema3()
{
}


void Tema3::Init()
{
    const string sourceTextureDir = PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "Tema3", "textures");
    player_size = 0.4f;
    gift_size = 0.25f;
    camera = new implemented::Camera3();
    time = 0;
    x = 0;
    y = 0;
    z = -4.5f;
    prev_z = 0;
    prev_z2 = 0;
    prev_z_pietre = 0;
    prev_z2_pietre = 0;
    prev_z_stalpi = 0;
    prev_z2_stalpi = 0;
    prev_z_cadou = 0;
    prev_z2_cadou = 0;
    angle = 0;
    x_plane = 0;
    y_plane = 0;
    z_plane = 0;
    camera_y = 5;
    camera_z = 6;
    scor = 0;
    viteza = 2;

    braduti.push_back(glm::vec3(2, 0.2f, -2));
    braduti.push_back(glm::vec3(6, 0.2f, 0));
    braduti.push_back(glm::vec3(4, 0.2f, 14));
    braduti.push_back(glm::vec3(5.5, 0.2f, -3.5f));
    braduti.push_back(glm::vec3(9, 0.2f, 2));
    braduti.push_back(glm::vec3(8, 0.2f, 0));
    braduti.push_back(glm::vec3(2, 0.2f, 16));
    braduti.push_back(glm::vec3(6, 0.2f, 5));
    braduti.push_back(glm::vec3(4, 0.2f, -1.5f));
    braduti.push_back(glm::vec3(5.5, 0.2f, 10.7f));
    braduti.push_back(glm::vec3(8.6f, 0.2f,2.1f ));
    braduti.push_back(glm::vec3(-8, 0.2f, 0));
    braduti.push_back(glm::vec3(-9, 0.2f, 5));
    braduti.push_back(glm::vec3(-6.2, 0.2f, 10));
    braduti.push_back(glm::vec3(-5.5, 0.2f, 13));
    braduti.push_back(glm::vec3(-2, 0.2f, 17));
    braduti.push_back(glm::vec3(-6, 0.2f, -5));
    braduti.push_back(glm::vec3(-10, 0.2f, 16));
    braduti.push_back(glm::vec3(-4, 0.2f, 4));
    braduti.push_back(glm::vec3(-5.5, 0.2f, 6));

    for (int i = 0; i < braduti.size(); i++) {
        aux.push_back(braduti.at(i));
        aux2.push_back(braduti.at(i));

    }


    cadouri.push_back({ glm::vec3(2.5f, 0.2f, 0), true });
    cadouri.push_back({glm::vec3(-2.3f, 0.2f, 1.5f),true });
    cadouri.push_back({glm::vec3(-5, 0.2f, 3),true });
    cadouri.push_back({glm::vec3(-8, 0.2f, 4),true });
    cadouri.push_back({glm::vec3(3, 0.2f, 6),true });
    cadouri.push_back({glm::vec3(-1, 0.2f, 7),true });
    cadouri.push_back({glm::vec3(5, 0.2f, 7.6),true });
    cadouri.push_back({glm::vec3(7, 0.2f, 8),true });
    cadouri.push_back({ glm::vec3(4, 0.2f, 9),true });

    cadouri.push_back({ glm::vec3(0, 0.2f, 1.6f),true });
    cadouri.push_back({ glm::vec3(1.2f, 0.2f, 7),true });
    cadouri.push_back({ glm::vec3(-1.3f, 0.2f, 4),true });

    for (int i = 0; i < cadouri.size(); i++) {
        cadou_aux.push_back(cadouri.at(i));
        cadou_aux2.push_back(cadouri.at(i));

    }


    pietre.push_back(glm::vec3(2.5f, 0.2f, -2));
    pietre.push_back(glm::vec3(-5, 0.2f, -2));
    pietre.push_back(glm::vec3(-4, 0.2f, 5));
    pietre.push_back(glm::vec3(-2.8, 0.2f, 0));
    pietre.push_back(glm::vec3(8, 0.2f, 16));
    pietre.push_back(glm::vec3(-3.9f, 0.2f, 12));
    pietre.push_back(glm::vec3(3, 0.2f, 18));
    pietre.push_back(glm::vec3(5.3f, 0.2f, 19));
    pietre.push_back(glm::vec3(-6.2f, 0.2f, 14.5f));
    pietre.push_back(glm::vec3(0, 0.2f, 20));
    pietre.push_back(glm::vec3(2.9f, 0.2f, 3));
    pietre.push_back(glm::vec3(7.2f, 0.2f, 5));
    pietre.push_back(glm::vec3(-5.4f, 0.2f, 8));

    for (int i = 0; i < pietre.size(); i++) {
        aux_pietre.push_back(pietre.at(i));
        aux2_pietre.push_back(pietre.at(i));

    }


    stalpi.push_back(glm::vec3(4, 0.2f, 2.3f));
    stalpi.push_back(glm::vec3(2.5, 0.2f, -3));

    stalpi.push_back(glm::vec3(-2, 0.2f, -3.5f));
    stalpi.push_back(glm::vec3(-8, 0.2f, -2.8f));
    stalpi.push_back(glm::vec3(-4.3f, 0.2f, 0));

    stalpi.push_back(glm::vec3(-3, 0.2f, 9));
    stalpi.push_back(glm::vec3(-4, 0.2f, 12));
    stalpi.push_back(glm::vec3(-6.2f, 0.2f, 4));

    stalpi.push_back(glm::vec3(5, 0.2f, 3.5f));
    stalpi.push_back(glm::vec3(4.2f, 0.2f, 7.3f));
    stalpi.push_back(glm::vec3(2.5, 0.2f, 13.5f));
    stalpi.push_back(glm::vec3(8.7f, 0.2f, 2.3f));
    stalpi.push_back(glm::vec3(7.3f, 0.2f, 17.5f));

    stalpi.push_back(glm::vec3(1.2f, 0.2f, -1.0f));
    stalpi.push_back(glm::vec3(0, 0.2f, 15.2f));
    stalpi.push_back(glm::vec3(10, 0.2f, 4.7f));

    for (int i = 0; i < stalpi.size(); i++) {
        aux_stalpi.push_back(stalpi.at(i));
        aux2_stalpi.push_back(stalpi.at(i));

    }


    camera->Set(glm::vec3(x,camera_y,z + camera_z), glm::vec3(x ,y,z), glm::vec3(0, 1, 0));
    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(sourceTextureDir, "gift1.jpg").c_str(), GL_REPEAT);
        mapTextures["gift1"] = texture;
    }

    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(sourceTextureDir, "metal1.jpg").c_str(), GL_REPEAT);
        mapTextures["metal1"] = texture;
    }

    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(sourceTextureDir, "snow2.jpg").c_str(), GL_REPEAT);
        mapTextures["snow2"] = texture;
    }

    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(sourceTextureDir, "snow4.jpg").c_str(), GL_REPEAT);
        mapTextures["snow4"] = texture;
    }


    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(sourceTextureDir, "tree1.jpg").c_str(), GL_REPEAT);
        mapTextures["tree1"] = texture;
    }

    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(sourceTextureDir, "schi1.jpg").c_str(), GL_REPEAT);
        mapTextures["schi1"] = texture;
    }

    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(sourceTextureDir, "rock2.jpg").c_str(), GL_REPEAT);
        mapTextures["rock2"] = texture;
    }

    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(sourceTextureDir, "wood1.jpg").c_str(), GL_REPEAT);
        mapTextures["wood1"] = texture;
    }
    {
        Texture2D* texture = new Texture2D();
        texture->Load2D(PATH_JOIN(sourceTextureDir, "schi2.jpg").c_str(), GL_REPEAT);
        mapTextures["schi2"] = texture;
    }

    


    // Load meshes
    {
        Mesh* mesh = new Mesh("box");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "box.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("cone");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "cone.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }
   

    {
        Mesh* mesh = new Mesh("sphere");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "sphere.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("plane");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "plane50.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("quad");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "quad.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }


   

    {
        vector<glm::vec3> vertices
        {
            glm::vec3(0.5f,   0.5f, 0.0f),    // top right
            glm::vec3(0.5f,  -0.5f, 0.0f),    // bottom right
            glm::vec3(-0.5f, -0.5f, 0.0f),    // bottom left
            glm::vec3(-0.5f,  0.5f, 0.0f),    // top left
        };

        vector<glm::vec3> normals
        {
            glm::vec3(0, 1, 1),
            glm::vec3(1, 0, 1),
            glm::vec3(1, 0, 0),
            glm::vec3(0, 1, 0)
        };

        vector<glm::vec2> textureCoords
        {
            glm::vec2(0.0f, 0.0f),
            glm::vec2(0.f, 1.f),
            glm::vec2(1.f, 1.f),
            glm::vec2(1.f, 0.f)

        };

        vector<unsigned int> indices =
        {
            0, 1, 3,
            1, 2, 3
        };

        Mesh* mesh = new Mesh("square");
        mesh->InitFromData(vertices, normals, textureCoords, indices);
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Shader *shader = new Shader("LabShader");
        shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "Tema3", "shaders", "VertexShader.glsl"), GL_VERTEX_SHADER);
        shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "Tema3", "shaders", "FragmentShader.glsl"), GL_FRAGMENT_SHADER);
        shader->CreateAndLink();
        shaders[shader->GetName()] = shader;
    }
}


void Tema3::FrameStart()
{
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    glViewport(0, 0, resolution.x, resolution.y);
}


bool Tema3::Coliziune(glm::vec3 Point) {
    bool rez = false;
    for (int i = 0; i < 9; i++) {
        if (sqrt((Point.x - x) * (Point.x - x) + (Point.z - z) * (Point.z - z)) <= player_size + gift_size) {
            rez = true;
            break;
        }

    }
    return rez;
}


void Tema3::RenderScene(float deltaTimeSeconds) {

    


    // bradut
    for (int i = 0; i < braduti.size(); i++) {
      
        if (z > prev_z + 30) {

            aux.at(i) = braduti.at(i) + glm::vec3(0, 0, z+10);
           
            if (i == braduti.size() - 1) {
                prev_z = z;
            }

        }
        if (z > prev_z2 + 40) {

            aux2.at(i) = braduti.at(i) + glm::vec3(0, 0, z + 15);

            if (i == braduti.size() - 1) {
                prev_z2 = z;
            }

        }

        if (Coliziune(braduti.at(i)) || Coliziune(aux.at(i)) || Coliziune(aux2.at(i))) {
            scor -= 50;
            time = 10;
        }
       
        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, braduti.at(i) + glm::vec3(0, 0.6f, 0));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.4f));

            RenderSimpleMesh(meshes["cone"], shaders["LabShader"], modelMatrix, mapTextures["tree1"]);

        }
        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, braduti.at(i) + glm::vec3(0, 1, 0));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.25f));
            RenderSimpleMesh(meshes["cone"], shaders["LabShader"], modelMatrix, mapTextures["tree1"]);

        }
        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, braduti.at(i));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.15f, 0.7, 0.15f));
            RenderSimpleMesh(meshes["box"], shaders["LabShader"], modelMatrix, mapTextures["wood1"]);

        }

       

        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, aux.at(i) + glm::vec3(0, 0.6f, 0));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.4f));
            RenderSimpleMesh(meshes["cone"], shaders["LabShader"], modelMatrix, mapTextures["tree1"]);
        }

        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, aux.at(i) + glm::vec3(0, 1, 0));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.25f));
            RenderSimpleMesh(meshes["cone"], shaders["LabShader"], modelMatrix, mapTextures["tree1"]);
        }

        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, aux.at(i));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.15f, 0.7, 0.15f));
            RenderSimpleMesh(meshes["box"], shaders["LabShader"], modelMatrix, mapTextures["wood1"]);
        }

        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, aux2.at(i) + glm::vec3(0, 0.6f, 0));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.4f));
            RenderSimpleMesh(meshes["cone"], shaders["LabShader"], modelMatrix, mapTextures["tree1"]);
        }

        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, aux2.at(i) + glm::vec3(0, 1, 0));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.25f));
            RenderSimpleMesh(meshes["cone"], shaders["LabShader"], modelMatrix, mapTextures["tree1"]);
        }

        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, aux2.at(i));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.15f, 0.7, 0.15f));
            RenderSimpleMesh(meshes["box"], shaders["LabShader"], modelMatrix, mapTextures["wood1"]);
        }

       
           



    }


        // pietre
    for (int i = 0; i < pietre.size(); i++) {

        if (z > prev_z_pietre + 20) {

            aux_pietre.at(i) = pietre.at(i) + glm::vec3(0, 0, z + 5);

            if (i == pietre.size() - 1) {
                prev_z_pietre = z;
            }

        }
        if (z > prev_z2_pietre + 30) {

            aux2_pietre.at(i) = pietre.at(i) + glm::vec3(0, 0, z + 20);

            if (i == pietre.size() - 1) {
                prev_z2_pietre = z;
            }

        }
        if (Coliziune(pietre.at(i)) || Coliziune(aux_pietre.at(i)) || Coliziune(aux2_pietre.at(i))) {
            scor -= 50;
            time = 10;
        }
        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, pietre.at(i) + glm::vec3(-0.13f, 0, 0.1));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.1f));
            RenderSimpleMesh(meshes["sphere"], shaders["LabShader"], modelMatrix, mapTextures["rock2"]);
        }
        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, pietre.at(i));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.2f));
            RenderSimpleMesh(meshes["sphere"], shaders["LabShader"], modelMatrix, mapTextures["rock2"]);
        }
        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, pietre.at(i) + glm::vec3(0.13f, 0, 0.1));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.15f));
            RenderSimpleMesh(meshes["sphere"], shaders["LabShader"], modelMatrix, mapTextures["rock2"]);
        }



        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, aux_pietre.at(i) + glm::vec3(-0.13f, 0, 0.1));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.1f));
            RenderSimpleMesh(meshes["sphere"], shaders["LabShader"], modelMatrix, mapTextures["rock2"]);
        }
        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, aux_pietre.at(i));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.2f));
            RenderSimpleMesh(meshes["sphere"], shaders["LabShader"], modelMatrix, mapTextures["rock2"]);
        }
        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, aux_pietre.at(i) + glm::vec3(0.13f, 0, 0.1));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.15f));
            RenderSimpleMesh(meshes["sphere"], shaders["LabShader"], modelMatrix, mapTextures["rock2"]);
        }

        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, aux2_pietre.at(i) + glm::vec3(-0.13f, 0, 0.1));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.1f));
            RenderSimpleMesh(meshes["sphere"], shaders["LabShader"], modelMatrix, mapTextures["rock2"]);
        }
        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, aux2_pietre.at(i));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.2f));
            RenderSimpleMesh(meshes["sphere"], shaders["LabShader"], modelMatrix, mapTextures["rock2"]);
        }
        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, aux2_pietre.at(i) + glm::vec3(0.13f, 0, 0.1));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.15f));
            RenderSimpleMesh(meshes["sphere"], shaders["LabShader"], modelMatrix, mapTextures["rock2"]);
        }





    }

       



    // cadou 

    for (int i = 0; i < cadouri.size(); i++) {

        if (z > prev_z_cadou + 20) {

            cadou_aux.at(i).poz = cadouri.at(i).poz + glm::vec3(0, 0, z + 5);

            if (i == cadouri.size() - 1) {
                prev_z_cadou = z;
            }

        }
        if (z > prev_z2_cadou + 30) {

            cadou_aux2.at(i).poz = cadouri.at(i).poz + glm::vec3(0, 0, z + 20);

            if (i == cadouri.size() - 1) {
                prev_z2_cadou = z;
            }

        }
        if (cadouri.at(i).ok && Coliziune(cadouri.at(i).poz)) {
            cadouri.at(i).ok = false;
            scor += 100;
        }
        if (cadou_aux.at(i).ok && Coliziune(cadou_aux.at(i).poz)) {
            cadou_aux.at(i).ok = false;
            scor += 100;
        }
        if (cadou_aux2.at(i).ok && Coliziune(cadou_aux2.at(i).poz)) {
            cadou_aux2.at(i).ok = false;
            scor += 100;
        }
        if (cadouri.at(i).ok){
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, cadouri.at(i).poz);
            modelMatrix = glm::scale(modelMatrix, glm::vec3(gift_size));
            RenderSimpleMesh(meshes["box"], shaders["LabShader"], modelMatrix, mapTextures["gift1"]);
        }
        if (cadou_aux.at(i).ok) {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, cadou_aux.at(i).poz);
            modelMatrix = glm::scale(modelMatrix, glm::vec3(gift_size));
            RenderSimpleMesh(meshes["box"], shaders["LabShader"], modelMatrix, mapTextures["gift1"]);
        }
        if (cadou_aux2.at(i).ok) {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, cadou_aux2.at(i).poz);
            modelMatrix = glm::scale(modelMatrix, glm::vec3(gift_size));
            RenderSimpleMesh(meshes["box"], shaders["LabShader"], modelMatrix, mapTextures["gift1"]);
        }

    }




        
        //stalp 
    for (int i = 0; i < stalpi.size(); i++) {
        if (z > prev_z_stalpi + 30) {

            aux_stalpi.at(i) = stalpi.at(i) + glm::vec3(0, 0, z + 10);

            if (i == stalpi.size() - 1) {
                prev_z_stalpi = z;
            }

        }
        if (z > prev_z2_stalpi + 40) {

            aux2_stalpi.at(i) = stalpi.at(i) + glm::vec3(0, 0, z + 15);

            if (i == stalpi.size() - 1) {
                prev_z2_stalpi = z;
            }

        }
        if (Coliziune(stalpi.at(i)) || Coliziune(aux_stalpi.at(i)) || Coliziune(aux2_stalpi.at(i))) {
            scor -= 50;
            time = 10;
        }
        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, stalpi.at(i));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.1f, 4, 0.01f));
            RenderSimpleMesh(meshes["box"], shaders["LabShader"], modelMatrix, mapTextures["metal1"]);
        }
        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, stalpi.at(i) + glm::vec3(0, 2, 0));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.5f, 0.05f, 0.1f));
            RenderSimpleMesh(meshes["box"], shaders["LabShader"], modelMatrix, mapTextures["metal1"]);
        }

        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, aux_stalpi.at(i));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.1f, 4, 0.01f));
            RenderSimpleMesh(meshes["box"], shaders["LabShader"], modelMatrix, mapTextures["metal1"]);
        }
        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, aux_stalpi.at(i) + glm::vec3(0, 2, 0));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.5f, 0.05f, 0.1f));
            RenderSimpleMesh(meshes["box"], shaders["LabShader"], modelMatrix, mapTextures["metal1"]);
        }

        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, aux2_stalpi.at(i));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.1f, 4, 0.01f));
            RenderSimpleMesh(meshes["box"], shaders["LabShader"], modelMatrix, mapTextures["metal1"]);
        }
        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, aux2_stalpi.at(i) + glm::vec3(0, 2, 0));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.5f, 0.05f, 0.1f));
            RenderSimpleMesh(meshes["box"], shaders["LabShader"], modelMatrix, mapTextures["metal1"]);
        }

    }




    // schior
    z += deltaTimeSeconds * viteza * cos (RADIANS(angle));
    x += deltaTimeSeconds * viteza * sin(RADIANS(angle));
    camera->Set(glm::vec3(x, camera_y, z + camera_z), glm::vec3(x, y, z), glm::vec3(0, 1, 0));

    
    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(x, y, z));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(player_size, player_size + 0.2f, player_size));
        modelMatrix = glm::rotate(modelMatrix, RADIANS(angle), glm::vec3(0, 1, 0));
       // modelMatrix = glm::rotate(modelMatrix, RADIANS(30.0f), glm::vec3(1, 0, 0));

        RenderSimpleMesh(meshes["box"], shaders["LabShader"], modelMatrix, mapTextures["schi2"]);
    }

    //schiuri
    {
        glm::mat4 modelMatrix = glm::mat4(1);

        modelMatrix = glm::translate(modelMatrix, glm::vec3(x-0.1f, 0, z));
        modelMatrix = glm::rotate(modelMatrix, RADIANS(angle), glm::vec3(0, 1, 0));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.1f, 0.05f, 1.3f));


        RenderSimpleMesh(meshes["box"], shaders["LabShader"], modelMatrix, mapTextures["schi1"]);
    }
    {
        glm::mat4 modelMatrix = glm::mat4(1);

        modelMatrix = glm::translate(modelMatrix, glm::vec3(x +0.1f, 0, z));
        modelMatrix = glm::rotate(modelMatrix, RADIANS(angle), glm::vec3(0, 1, 0));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.1f, 0.05f, 1.3f));


        RenderSimpleMesh(meshes["box"], shaders["LabShader"], modelMatrix, mapTextures["schi1"]);
    }
    
    
    

   
    //partie
     z_plane += deltaTimeSeconds * viteza * cos(RADIANS(angle));
    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(x_plane, y_plane, z_plane));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(50, 0, 50));
        modelMatrix = glm::rotate(modelMatrix, RADIANS(70.0f), glm::vec3(1, 0, 0));
        RenderSimpleMesh(meshes["quad"], shaders["LabShader"], modelMatrix, mapTextures["snow2"]);
    }

   




}
void Tema3::Update(float deltaTimeSeconds)
{
    glm::ivec2 resolution = window->GetResolution();
    gfxc::TextRenderer* textRenderer = new gfxc::TextRenderer(window->props.selfDir, resolution.x, resolution.y);
    textRenderer->Load(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::FONTS, "Hack-Bold.ttf"), 30);
    textRenderer->RenderText("Score:"+ std::to_string(scor), resolution.x  - 220, 50, 1.0f, glm::vec3(1, 1, 1));

    
    
    if (time > 0) {
        gfxc::TextRenderer* textRenderer = new gfxc::TextRenderer(window->props.selfDir, resolution.x, resolution.y);
        textRenderer->Load(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::FONTS, "Hack-Bold.ttf"), 30);
        textRenderer->RenderText("BOOM" , resolution.x - 220, 70, 1.0f, glm::vec3(1, 0, 0));
    }
    time--;

    
   
    RenderScene(deltaTimeSeconds);

  
}


void Tema3::FrameEnd()
{
   // DrawCoordinateSystem();
}


void Tema3::RenderSimpleMesh(Mesh *mesh, Shader *shader, const glm::mat4 & modelMatrix, Texture2D* texture1, Texture2D* texture2)
{
    if (!mesh || !shader || !shader->GetProgramID())
        return;

    glUseProgram(shader->program);

    GLint loc_model_matrix = glGetUniformLocation(shader->program, "Model");
    glUniformMatrix4fv(loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

    glm::mat4 viewMatrix = GetSceneCamera()->GetViewMatrix();
    int loc_view_matrix = glGetUniformLocation(shader->program, "View");
    //glUniformMatrix4fv(loc_view_matrix, 1, GL_FALSE, glm::value_ptr(viewMatrix));
    glUniformMatrix4fv(loc_view_matrix, 1, GL_FALSE, glm::value_ptr(camera->GetViewMatrix()));
    
    glm::mat4 projectionMatrix = GetSceneCamera()->GetProjectionMatrix();
    int loc_projection_matrix = glGetUniformLocation(shader->program, "Projection");
    glUniformMatrix4fv(loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));


    if (texture1)
    {
      
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture1->GetTextureID());
        glUniform1i(glGetUniformLocation(shader->program, "texture_1"), 0);

    }

    if (texture2)
    {
    
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture2->GetTextureID());
        glUniform1i(glGetUniformLocation(shader->program, "texture_2"), 1);
    }

    glBindVertexArray(mesh->GetBuffers()->m_VAO);
    glDrawElements(mesh->GetDrawMode(), static_cast<int>(mesh->indices.size()), GL_UNSIGNED_INT, 0);
}




void Tema3::OnInputUpdate(float deltaTime, int mods)
{
    

    if (!window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT))
    {
        glm::vec3 up = glm::vec3(0, 1, 0);
        glm::vec3 right = GetSceneCamera()->m_transform->GetLocalOXVector();
        glm::vec3 forward = GetSceneCamera()->m_transform->GetLocalOZVector();
        forward = glm::normalize(glm::vec3(forward.x, 0, forward.z));
    }

    float cameraSpeed = 2.0f;

    if (window->KeyHold(GLFW_KEY_W)) {
        camera->TranslateForward(cameraSpeed * deltaTime);

    }

    if (window->KeyHold(GLFW_KEY_A)) {
        camera->TranslateRight(-cameraSpeed * deltaTime);

    }

    if (window->KeyHold(GLFW_KEY_S)) {
        camera->TranslateForward(-cameraSpeed * deltaTime);

    }

    if (window->KeyHold(GLFW_KEY_D)) {
        camera->TranslateRight(cameraSpeed * deltaTime);

    }

    if (window->KeyHold(GLFW_KEY_Q)) {
        camera->TranslateUpward(-cameraSpeed * deltaTime);

    }

    if (window->KeyHold(GLFW_KEY_E)) {
        camera->TranslateUpward(cameraSpeed * deltaTime);

    }

    if (window->KeyHold(GLFW_KEY_R)) {
        x = 0;
        y = 0; 
        z = 0;
        scor = 0;

    }
}


void Tema3::OnKeyPress(int key, int mods)
{
}


void Tema3::OnKeyRelease(int key, int mods)
{
}


void Tema3::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    angle += deltaX * 0.5f;
   
    if (angle > 60) {
        angle = 60;
    }
    if (angle < - 60) {
        angle = -60;
    }

}


void Tema3::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
}


void Tema3::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
}


void Tema3::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Tema3::OnWindowResize(int width, int height)
{
}
