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
	// - TODO - CHARGE ALL THE VARIABLES IN THEHEADER WHEN FINISHED !!
	Cube left_limit(3,4,300);
	left_limit.SetPos(-10, 0, 0);
	Cube right_limit(3,4,300);
	right_limit.SetPos(10, 0, 0);
	//Waterfalls
	Cube top_plane(20, 2, 30);
	top_plane.SetPos(5, 10, -200);
	top_plane.color = Blue;

	Cube top_plane2(20, 2, 30);
	top_plane2.SetPos(5, 8, -170);
	top_plane2.color = Blue;


	Cube top_plane3(20, 2, 30);
	top_plane3.SetPos(5, 6, -140);
	top_plane3.color = Blue;


	Cube top_plane4(20, 2, 30);
	top_plane4.SetPos(10, 4, -110);
	top_plane4.color = Blue;


	Cube top_plane5(20, 2, 30);
	top_plane5.SetPos(10, 4, -110);
	top_plane5.color = Blue;
	top_plane.InnerRender();


	App->physics->AddBody(left_limit, 0);
	App->physics->AddBody(right_limit, 0);

	App->physics->AddBody(top_plane, 0);
	App->physics->AddBody(top_plane2, 0);
	App->physics->AddBody(top_plane3, 0);
	App->physics->AddBody(top_plane4, 0);
	App->physics->AddBody(top_plane5, 0);





}



