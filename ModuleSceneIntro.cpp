#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "ModulePhysics3D.h"
#include "Primitive.h"
#include "PhysVehicle3D.h"
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
	sensor_form = { 15,15,1 };
	App->audio->PlayMusic("soundtrack.ogg", 1);
	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));
	CreateLinearCircuit(vec3(10, 0, 0));
	start = end = false;
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
	//the start and end have to be moved to the first sensor and the last one not in the cave one
	if (body1 == sensor_p2 && body2 == App->player->vehicle)
	{
		//entrance fo the cave
		start = true;
		LOG("HIT!");
	}

	if (body1 == sensor_p3 && body2 == App->player->vehicle)
	{
		//out of the cave
		end = true;
		LOG("HIT!");
	}
	
}

void ModuleSceneIntro::CreateLinearCircuit(vec3 position)
{
	//----------SENSORS-----------
	sensor_start = App->physics->AddBody(sensor_form, 0.0f);
	sensor_start->SetAsSensor(true);
	//sensor_start->SetPos();
	sensor_start->GetTransform(&sensor_form.transform);
	sensor_start->collision_listeners.add(this);
	sensor_start->SetId(0);

	sensor_p1 = App->physics->AddBody(sensor_form, 0.0f);
	sensor_p1->SetAsSensor(true);
	//sensor_p1->SetPos();
	sensor_p1->GetTransform(&sensor_form.transform);
	sensor_p1->collision_listeners.add(this);
	sensor_p1->SetId(1);

	sensor_p2 = App->physics->AddBody(sensor_form, 0.0f);
	sensor_p2->SetAsSensor(true);
	sensor_p2->SetPos(5, 0, 30);//in tunel
	sensor_p2->GetTransform(&sensor_form.transform);
	sensor_p2->collision_listeners.add(this);
	sensor_p2->SetId(2);


	sensor_p3 = App->physics->AddBody(sensor_form, 0.0f);
	sensor_p3->SetAsSensor(true);
	sensor_p3->SetPos(-179, 0, 40);//out tunel
	sensor_p3->GetTransform(&sensor_form.transform);
	sensor_p3->collision_listeners.add(this);
	sensor_p3->SetId(3);


	sensor_p4 = App->physics->AddBody(sensor_form, 0.0f);
	sensor_p4->SetAsSensor(true);
	//sensor_p4->SetPos();
	sensor_p4->GetTransform(&sensor_form.transform);
	sensor_p4->collision_listeners.add(this);
	sensor_p4->SetId(4);


	sensor_p5 = App->physics->AddBody(sensor_form, 0.0f);
	sensor_p5->SetAsSensor(true);
	//sensor_p5->SetPos();
	sensor_p5->GetTransform(&sensor_form.transform);
	sensor_p5->collision_listeners.add(this);
	sensor_p5->SetId(5);


	sensor_p6 = App->physics->AddBody(sensor_form, 0.0f);
	sensor_p6->SetAsSensor(true);
	//sensor_p6->SetPos();
	sensor_p6->GetTransform(&sensor_form.transform);
	sensor_p6->collision_listeners.add(this);
	sensor_p6->SetId(6);
	int i = 0;
	//-----P1---------

	// - TODO - CHARGE ALL THE VARIABLES IN THEHEADER WHEN FINISHED !!
	//it's at home 
	CircuitPolygon.PushBack(Cube(5, 1, 25));
	CircuitPolygon[i].color = Red;
	CircuitPolygon[i].SetPos(-179, 6.5, 15);
	CircuitPolygon[i].SetRotation(30, vec3(1, 0, 0));
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(25, 1, 5));
	CircuitPolygon[i].color = Red;
	CircuitPolygon[i].SetPos(-185, 13, 2);
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(25, 1, 5));
	CircuitPolygon[i].color = Red;
	CircuitPolygon[i].SetPos(-207, 13, -4);
	CircuitPolygon[i].SetRotation(-30, vec3(0, 1, 0));
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;

	CircuitPolygon.PushBack(Cube(25, 1, 5));
	CircuitPolygon[i].color = Red;
	CircuitPolygon[i].SetPos(-212, 13, -20);
	CircuitPolygon[i].SetRotation(70, vec3(0, 1, 0));
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;


	CircuitPolygon.PushBack(Cube(15, 1, 5));
	CircuitPolygon[i].color = Red;
	CircuitPolygon[i].SetPos(-202, 13, -32);
	CircuitPolygon[i].SetRotation(15, vec3(0, 1, 0));
	App->physics->AddBody(CircuitPolygon[i], 0);
	i++;
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



