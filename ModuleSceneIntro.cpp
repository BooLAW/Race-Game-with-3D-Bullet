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
	//it's at home 
	App->physics->AddBody(start_plane, 0);
	App->physics->AddBody(second_plane, 0);
	//-----P2---------
	Cube before_tunel(10, 1, 25);
	before_tunel.SetPos(5, 0, 30);
	App->physics->AddBody(before_tunel, 0);
	
	Cube before_tunel_wall1(1, 10, 25);
	before_tunel_wall1.SetPos(10, 0, 30);
	App->physics->AddBody(before_tunel_wall1, 0);
	
	Cube before_tunel_wall2(1, 10, 25);
	before_tunel_wall2.SetPos(0, 0, 30);
	App->physics->AddBody(before_tunel_wall2, 0);


	Cube tunel_curve1(10,1,30);
	tunel_curve1.SetPos(2, 0, 55);
	tunel_curve1.SetRotation(-15, { 0,1,0 });
	App->physics->AddBody(tunel_curve1, 0);
	

	Cube tunel_curve1_wall1(1, 10, 30);
	tunel_curve1_wall1.SetPos(7, 0, 55);
	tunel_curve1_wall1.SetRotation(-15, { 0,1,0 });
	App->physics->AddBody(tunel_curve1_wall1, 0);

	Cube tunel_curve1_wall2(1, 10, 30);
	tunel_curve1_wall2.SetPos(-3, 0, 55);
	tunel_curve1_wall2.SetRotation(-15, { 0,1,0 });
	App->physics->AddBody(tunel_curve1_wall2, 0);

	Cube tunel_curve1_top(10, 1, 30);
	tunel_curve1_top.SetPos(2, 5, 55);
	tunel_curve1_top.SetRotation(-15, { 0,1,0 });
	App->physics->AddBody(tunel_curve1_top, 0);

	Cube tunel_curve2(10, 1, 30);
	tunel_curve2.SetPos(-9, 0, 80);
	tunel_curve2.SetRotation(-30, { 0,1,0 });
	App->physics->AddBody(tunel_curve2, 0);

	Cube tunel_curve2_wall1(1, 10, 30);
	tunel_curve2_wall1.SetPos(-14, 0, 80);
	tunel_curve2_wall1.SetRotation(-30, { 0,1,0 });
	App->physics->AddBody(tunel_curve2_wall1, 0);

	Cube tunel_curve2_wall2(1, 10, 30);
	tunel_curve2_wall2.SetPos(-4, 0, 80);
	tunel_curve2_wall2.SetRotation(-30, { 0,1,0 });
	App->physics->AddBody(tunel_curve2_wall2, 0);

	Cube tunel_curve2_top(10, 1, 30);
	tunel_curve2_top.SetPos(-9, 5, 80);
	tunel_curve2_top.SetRotation(-30, { 0,1,0 });
	App->physics->AddBody(tunel_curve2_top, 0);

	Cube tunel_curve3(10, 1, 30);
	tunel_curve3.SetPos(-25, 0, 100);
	tunel_curve3.SetRotation(-45, { 0,1,0 });
	App->physics->AddBody(tunel_curve3, 0);

	Cube tunel_curve3_wall1(1, 10, 30);
	tunel_curve3_wall1.SetPos(-31, 0, 100);
	tunel_curve3_wall1.SetRotation(-45, { 0,1,0 });
	App->physics->AddBody(tunel_curve3_wall1, 0);

	Cube tunel_curve3_wall2(1, 10, 30);
	tunel_curve3_wall2.SetPos(-19, 0, 100);
	tunel_curve3_wall2.SetRotation(-45, { 0,1,0 });
	App->physics->AddBody(tunel_curve3_wall2, 0);

	Cube tunel_curve3_top(10, 1, 30);
	tunel_curve3_top.SetPos(-25, 5, 100);
	tunel_curve3_top.SetRotation(-45, { 0,1,0 });
	App->physics->AddBody(tunel_curve3_top, 0);

	Cube tunel_curve4(10, 1, 30);
	tunel_curve4.SetPos(-45, 0, 115);
	tunel_curve4.SetRotation(-60, { 0,1,0 });
	App->physics->AddBody(tunel_curve4, 0);

	Cube tunel_curve4_wall1(1, 10, 30);
	tunel_curve4_wall1.SetPos(-47, 0, 110);
	tunel_curve4_wall1.SetRotation(-60, { 0,1,0 });
	App->physics->AddBody(tunel_curve4_wall1, 0);

	Cube tunel_curve4_wall2(1, 10, 30);
	tunel_curve4_wall2.SetPos(-40, 0, 118);
	tunel_curve4_wall2.SetRotation(-60, { 0,1,0 });
	App->physics->AddBody(tunel_curve4_wall2, 0);

	Cube tunel_curve4_top(10, 1, 30);
	tunel_curve4.SetPos(-45, 5, 115);
	tunel_curve4.SetRotation(-60, { 0,1,0 });
	App->physics->AddBody(tunel_curve4, 0);

	Cube tunel_curve5(10, 1, 30);
	tunel_curve5.SetPos(-70, 0, 125);
	tunel_curve5.SetRotation(-75, { 0,1,0 });
	App->physics->AddBody(tunel_curve5, 0);

	Cube tunel_curve5_wall1(1, 10, 30);
	tunel_curve5_wall1.SetPos(-75, 0, 125);
	tunel_curve5_wall1.SetRotation(-75, { 0,1,0 });
	App->physics->AddBody(tunel_curve5_wall1, 0);

	Cube tunel_curve5_wall2(1, 10, 30);
	tunel_curve5_wall2.SetPos(-65, 0, 125);
	tunel_curve5_wall2.SetRotation(-75, { 0,1,0 });
	App->physics->AddBody(tunel_curve5_wall2, 0);

	Cube tunel_curve5_top(10, 1, 30);
	tunel_curve5_top.SetPos(-70, 0, 125);
	tunel_curve5_top.SetRotation(-75, { 0,1,0 });
	App->physics->AddBody(tunel_curve5_top, 0);

	Cube tunel_curve6(10, 1, 30);
	tunel_curve6.SetPos(-97, 0, 129);
	tunel_curve6.SetRotation(-90, { 0,1,0 });

	Cube tunel_curve7(10, 1, 30);
	tunel_curve7.SetPos(-125, 0, 125);
	tunel_curve7.SetRotation(70, { 0,1,0 });

	Cube tunel_curve8(10, 1, 30);
	tunel_curve8.SetPos(-148, 0, 110);
	tunel_curve8.SetRotation(45 ,{ 0,1,0 });

	Cube tunel_curve9(10, 1, 30);
	tunel_curve9.SetPos(-163, 0, 90);
	tunel_curve9.SetRotation(30, { 0,1,0 });

	Cube tunel_curve10(10, 1, 30);
	tunel_curve10.SetPos(-175, 0, 63);
	tunel_curve10.SetRotation(15, { 0,1,0 });

	Cube after_tunel(10, 1, 25);
	after_tunel.SetPos(-179, 0, 40);






	
	
	
	App->physics->AddBody(tunel_curve5, 0);
	App->physics->AddBody(tunel_curve6, 0);
	App->physics->AddBody(tunel_curve7, 0);
	App->physics->AddBody(tunel_curve8, 0);
	App->physics->AddBody(tunel_curve9, 0);
	App->physics->AddBody(tunel_curve10, 0);
	App->physics->AddBody(after_tunel, 0);

	


	



}



