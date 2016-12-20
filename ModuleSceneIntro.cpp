#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "ModulePhysics3D.h"
#include "Primitive.h"
#include "PhysBody3D.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;
	App->audio->PlayMusic("soundtrack.ogg", 1);
	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));
	CreateLinearCircuit(vec3(10, 0, 0));

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();
	p.color = Blue;

	for (int i = 0; i < CircuitPolygon.Count(); i++)
	{
		CircuitPolygon[i].Render();
	}

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{

}

void ModuleSceneIntro::CreateLinearCircuit(vec3 position)
{
	int i = 0;
	//-----P1---------

	// - TODO - CHARGE ALL THE VARIABLES IN THEHEADER WHEN FINISHED !!
	//it's at home 

	//-----P2---------
	CircuitPolygon.PushBack(Cube(10, 1, 30));
	CircuitPolygon[i].SetPos(5, 0, 30);
	CircuitPolygon[i].color = Blue;
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;
	CircuitPolygon.PushBack(Cube(1, 10, 30));	
	CircuitPolygon[i].SetPos(10, 0, 30);
	CircuitPolygon[i].color = Black;
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;
	CircuitPolygon.PushBack(Cube(1, 10, 30));	
	CircuitPolygon[i].SetPos(0, 0, 30);
	CircuitPolygon[i].color = Black;
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(10, 1, 30));
	CircuitPolygon[i].SetPos(2, 0, 55);
	CircuitPolygon[i].SetRotation(-15, { 0,1,0 });
	CircuitPolygon[i].color = Blue;
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(1, 10, 30));	
	CircuitPolygon[i].SetPos(7, 0, 55);
	CircuitPolygon[i].SetRotation(-15, { 0,1,0 });
	CircuitPolygon[i].color = Black;
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(1, 10, 30));	
	CircuitPolygon[i].SetPos(-3, 0, 55);
	CircuitPolygon[i].SetRotation(-15, { 0,1,0 });
	CircuitPolygon[i].color = Black;
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(10, 1, 30));
	CircuitPolygon[i].SetPos(2, 5, 55);
	CircuitPolygon[i].SetRotation(-15, { 0,1,0 });
	CircuitPolygon[i].color = Black;
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(10, 1, 30));
	CircuitPolygon[i].SetPos(-9, 0, 80);
	CircuitPolygon[i].color = Blue;
	CircuitPolygon[i].SetRotation(-30, { 0,1,0 });
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(1, 10, 25));		
	CircuitPolygon[i].SetPos(-14, 0, 80);
	CircuitPolygon[i].SetRotation(-30, { 0,1,0 });
	CircuitPolygon[i].color = Black;
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(1, 10, 25));		
	CircuitPolygon[i].SetPos(-4, 0, 80);
	CircuitPolygon[i].SetRotation(-30, { 0,1,0 });
	CircuitPolygon[i].color = Black;
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(10, 1, 30));
	CircuitPolygon[i].SetPos(-9, 5, 80);
	CircuitPolygon[i].SetRotation(-30, { 0,1,0 });
	CircuitPolygon[i].color = Black;
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(10, 1, 30));
	CircuitPolygon[i].SetPos(-25, 0, 100);
	CircuitPolygon[i].color = Blue;
	CircuitPolygon[i].SetRotation(-45, { 0,1,0 });
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(1, 10, 25));
	CircuitPolygon[i].SetPos(-31, 0, 100);
	CircuitPolygon[i].SetRotation(-45, { 0,1,0 });
	CircuitPolygon[i].color = Black;
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(1, 10, 25));
	CircuitPolygon[i].SetPos(-19, 0, 100);
	CircuitPolygon[i].SetRotation(-45, { 0,1,0 });
	CircuitPolygon[i].color = Black;
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(10, 1, 30));
	CircuitPolygon[i].SetPos(-25, 5, 100);
	CircuitPolygon[i].SetRotation(-45, { 0,1,0 });
	CircuitPolygon[i].color = Black;
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(10, 1, 30));
	CircuitPolygon[i].SetPos(-45, 0, 115);
	CircuitPolygon[i].color = Blue;
	CircuitPolygon[i].SetRotation(-60, { 0,1,0 });
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(1, 10, 25));
	CircuitPolygon[i].SetPos(-47, 0, 110);
	CircuitPolygon[i].SetRotation(-60, { 0,1,0 });
	CircuitPolygon[i].color = Black;
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(1, 10, 25));
	CircuitPolygon[i].SetPos(-40, 0, 118);
	CircuitPolygon[i].SetRotation(-60, { 0,1,0 });
	CircuitPolygon[i].color = Black;
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(10, 1, 30));
	CircuitPolygon[i].SetPos(-45, 5, 115);
	CircuitPolygon[i].SetRotation(-60, { 0,1,0 });
	CircuitPolygon[i].color = Black;
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(10, 1, 30));
	CircuitPolygon[i].SetPos(-70, 0, 125);
	CircuitPolygon[i].color = Blue;
	CircuitPolygon[i].SetRotation(-75, { 0,1,0 });
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(1, 10, 30));
	CircuitPolygon[i].SetPos(-75, 0, 121);
	CircuitPolygon[i].SetRotation(-75, { 0,1,0 });
	CircuitPolygon[i].color = Black;
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(1, 10, 30));
	CircuitPolygon[i].SetPos(-70, 0, 130);
	CircuitPolygon[i].SetRotation(-75, { 0,1,0 });
	CircuitPolygon[i].color = Black;
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(10, 1, 30));
	CircuitPolygon[i].SetPos(-70, 5, 125);
	CircuitPolygon[i].SetRotation(-75, { 0,1,0 });
	CircuitPolygon[i].color = Black;
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(10, 1, 30));
	CircuitPolygon[i].color = Blue;
	CircuitPolygon[i].SetPos(-97, 0, 129);
	CircuitPolygon[i].SetRotation(-90, { 0,1,0 });
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(1, 10, 30));
	CircuitPolygon[i].SetPos(-101, 0, 134);
	CircuitPolygon[i].SetRotation(-90, { 0,1,0 });
	CircuitPolygon[i].color = Black;
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(1, 10, 30));
	CircuitPolygon[i].SetPos(-105, 0, 124);
	CircuitPolygon[i].SetRotation(-90, { 0,1,0 });
	CircuitPolygon[i].color = Black;
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(10, 1, 30));
	CircuitPolygon[i].SetPos(-97, 5, 129);
	CircuitPolygon[i].SetRotation(-90, { 0,1,0 });
	CircuitPolygon[i].color = Black;
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(10, 1, 30));
	CircuitPolygon[i].color = Blue;
	CircuitPolygon[i].SetPos(-125, 0, 125);
	CircuitPolygon[i].SetRotation(70, { 0,1,0 });
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(1, 10, 30));
	CircuitPolygon[i].SetPos(-125, 0, 130);
	CircuitPolygon[i].SetRotation(70, { 0,1,0 });
	CircuitPolygon[i].color = Black;
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(1, 10, 30));
	CircuitPolygon[i].SetPos(-125, 0, 120);
	CircuitPolygon[i].SetRotation(70, { 0,1,0 });
	CircuitPolygon[i].color = Black;
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(10, 1, 30));
	CircuitPolygon[i].SetPos(-125, 5, 125);
	CircuitPolygon[i].SetRotation(70, { 0,1,0 });
	CircuitPolygon[i].color = Black;
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(10, 1, 30));
	CircuitPolygon[i].color = Blue;
	CircuitPolygon[i].SetPos(-148, 0, 110);
	CircuitPolygon[i].SetRotation(45 ,{ 0,1,0 });
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(1, 10, 30));
	CircuitPolygon[i].SetPos(-148, 0, 103);
	CircuitPolygon[i].SetRotation(45, { 0,1,0 });
	CircuitPolygon[i].color = Black;
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(1, 10, 30));
	CircuitPolygon[i].SetPos(-148, 0, 117);
	CircuitPolygon[i].SetRotation(45, { 0,1,0 });
	CircuitPolygon[i].color = Black;
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(10, 1, 30));
	CircuitPolygon[i].SetPos(-148, 5, 110);
	CircuitPolygon[i].SetRotation(45, { 0,1,0 });
	CircuitPolygon[i].color = Black;
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(10, 1, 30));
	CircuitPolygon[i].color = Blue;
	CircuitPolygon[i].SetPos(-163, 0, 90);
	CircuitPolygon[i].SetRotation(30, { 0,1,0 });
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(1, 10, 30));
	CircuitPolygon[i].SetPos(-170, 0, 89);
	CircuitPolygon[i].SetRotation(30, { 0,1,0 });
	CircuitPolygon[i].color = Black;
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(1, 10, 30));
	CircuitPolygon[i].SetPos(-163, 0, 80);
	CircuitPolygon[i].color = Black;
	CircuitPolygon[i].SetRotation(30, { 0,1,0 });
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(10, 1, 30));
	CircuitPolygon[i].SetPos(-163, 5, 90);
	CircuitPolygon[i].color = Black;
	CircuitPolygon[i].SetRotation(30, { 0,1,0 });
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(10, 1, 30));
	CircuitPolygon[i].color = Blue;
	CircuitPolygon[i].SetPos(-175, 0, 63);
	CircuitPolygon[i].SetRotation(15, { 0,1,0 });
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(1, 10, 30));
	CircuitPolygon[i].SetPos(-178, 0, 71);
	CircuitPolygon[i].SetRotation(15, { 0,1,0 });
	CircuitPolygon[i].color = Black;
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(1, 10, 30));
	CircuitPolygon[i].SetPos(-170, 0, 60);
	CircuitPolygon[i].SetRotation(15, { 0,1,0 });
	CircuitPolygon[i].color = Black;
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(10, 1, 30));
	CircuitPolygon[i].SetPos(-175, 5, 63);
	CircuitPolygon[i].SetRotation(15, { 0,1,0 });
	CircuitPolygon[i].color = Black;
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;
	
	CircuitPolygon.PushBack(Cube(10, 1, 30));
	CircuitPolygon[i].color = Blue;
	CircuitPolygon[i].SetPos(-179, 0, 40);
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;
	CircuitPolygon.PushBack(Cube(1, 10, 30));
	CircuitPolygon[i].color = Black;
	CircuitPolygon[i].SetPos(-184, 0, 40);
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;
	CircuitPolygon.PushBack(Cube(1, 10, 30));
	CircuitPolygon[i].color = Black;
	CircuitPolygon[i].SetPos(-174, 0, 40);
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;



	// ---- P5 & P6
	CircuitPolygon.PushBack(Cube(20, 1, 100));
	CircuitPolygon[i].SetPos(-28, 0.5, 0);
	CircuitPolygon[i].SetRotation(45, vec3(0, 1, 0));
	CircuitPolygon[i].color = LightBlue;
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(20, 1, 100));
	CircuitPolygon[i].SetPos(28, 0, 0);
	CircuitPolygon[i].SetRotation(-45, vec3(0, 1, 0));
	App->physics->AddBody(CircuitPolygon[i], 0);
	CircuitPolygon[i].color = LightBlue;

	i++;

	CircuitPolygon.PushBack(Cube(35, 1, 35));
	CircuitPolygon[i].SetPos(0, 0.5, 0);
	App->physics->AddBody(CircuitPolygon[i], 0);
	CircuitPolygon[i].color = LightBlue;

	i++;

	CircuitPolygon.PushBack(Cube(140, 1, 20));
	CircuitPolygon[i].SetPos(0, 0.5, -37);
	App->physics->AddBody(CircuitPolygon[i], 0);
	CircuitPolygon[i].color = LightBlue;

	i++;

	CircuitPolygon.PushBack(Cube(35, 1, 45));
	CircuitPolygon[i].SetPos(-21, 0, -20);
	CircuitPolygon[i].SetRotation(90, vec3(0, 1, 0));
	App->physics->AddBody(CircuitPolygon[i], 0);
	CircuitPolygon[i].color = LightBlue;

	i++;

	CircuitPolygon.PushBack(Cube(45, 1, 35));
	CircuitPolygon[i].SetPos(21, 0.5, -20);
	App->physics->AddBody(CircuitPolygon[i], 0);
	CircuitPolygon[i].color = LightBlue;
	i++;

	CircuitPolygon.PushBack(Cube(30, 1, 100));
	CircuitPolygon[i].SetPos(0, 0, 75);
	App->physics->AddBody(CircuitPolygon[i], 0);
	CircuitPolygon[i].color = LightBlue;
	i++;

	CircuitPolygon.PushBack(Cube(140, 1, 20));
	CircuitPolygon[i].SetPos(0, 5, -37);
	CircuitPolygon[i].SetRotation(30, vec3(1, 0, 0));
	App->physics->AddBody(CircuitPolygon[i], 0);
	CircuitPolygon[i].color = LightBlue;
	i++;

	CircuitPolygon.PushBack(Cube(30, 1, 30));
	CircuitPolygon[i].SetPos(0, 0, -170);
	App->physics->AddBody(CircuitPolygon[i], 0);
	CircuitPolygon[i].color = LightBlue;
	i++;

	CircuitPolygon.PushBack(Cube(30, 1, 30));
	CircuitPolygon[i].SetPos(15, 0, -176);
	CircuitPolygon[i].SetRotation(45, vec3(0, 1, 0));
	App->physics->AddBody(CircuitPolygon[i], 0);
	CircuitPolygon[i].color = LightBlue;
	i++;

	CircuitPolygon.PushBack(Cube(30, 1, 30));
	CircuitPolygon[i].SetPos(-15, 0, -176);
	CircuitPolygon[i].SetRotation(-45, vec3(0, 1, 0));
	App->physics->AddBody(CircuitPolygon[i], 0);
	CircuitPolygon[i].color = LightBlue;
	i++;

	CircuitPolygon.PushBack(Cube(74, 1, 30));
	CircuitPolygon[i].SetPos(0, 0, -190);
	App->physics->AddBody(CircuitPolygon[i], 0);
	CircuitPolygon[i].color = LightBlue;






	
	
	

	


	



}



