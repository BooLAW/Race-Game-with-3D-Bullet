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

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{

}

void ModuleSceneIntro::CreateLinearCircuit(vec3 position)
{
	//-----P1---------
	Cube start_plane(20,1,25);
	start_plane.SetPos(5, 10, -180);

	Cube second_plane(20,1,25);
	second_plane.SetPos(5, 9, -162);

	// - TODO - CHARGE ALL THE VARIABLES IN THEHEADER WHEN FINISHED !!

	App->physics->AddBody(start_plane, 0);
	App->physics->AddBody(second_plane, 0);
	//-----P2---------

}



