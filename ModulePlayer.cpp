#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "Primitive.h"
#include "PhysVehicle3D.h"
#include "PhysBody3D.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled), vehicle(NULL)
{
	turn = acceleration = brake = 0.0f;
	nitro = 50;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	VehicleInfo car;

	// Car properties ----------------------------------------
	car.chassis_size.Set(2, 1, 4);
	car.chassis_offset.Set(0, 1.5, 0);
	car.mass = 1500.0f;
	car.suspensionStiffness = 10.88f;
	car.suspensionCompression = 0.83f;
	car.suspensionDamping = 0.1f;
	car.maxSuspensionTravelCm = 50.0f;
	car.frictionSlip = 50.5;
	car.maxSuspensionForce = 6000.0f;
	

	// Wheel properties ---------------------------------------
	float connection_height = 1.2f;
	float wheel_radius = 0.6f;
	float wheel_width = 0.5f;
	float suspensionRestLength = 1.2f;

	// Don't change anything below this line ------------------

	float half_width = car.chassis_size.x*0.5f;
	float half_length = car.chassis_size.z*0.5f;
	
	vec3 direction(0,-1,0);
	vec3 axis(-1,0,0);
	
	car.num_wheels = 4;
	car.wheels = new Wheel[4];

	// BACK - LEFT ------------------------
	car.wheels[0].connection.Set(half_width + 0.5*wheel_width, connection_height+0.5, -half_length + wheel_radius/*half_length - wheel_radius*/);
	car.wheels[0].direction = direction;
	car.wheels[0].axis = axis;	
	car.wheels[0].suspensionRestLength = suspensionRestLength;
	car.wheels[0].radius = wheel_radius;
	car.wheels[0].width = wheel_width;
	car.wheels[0].front = false;
	car.wheels[0].drive = true;
	car.wheels[0].brake = true;
	car.wheels[0].steering = false;

	// FRONT-LEFT ------------------------
	car.wheels[1].connection.Set(half_width + 0.5*wheel_width, connection_height, half_length);
	car.wheels[1].direction = direction;
	car.wheels[1].axis = axis;
	car.wheels[1].suspensionRestLength = suspensionRestLength;
	car.wheels[1].radius = wheel_radius;
	car.wheels[1].width = wheel_width;
	car.wheels[1].front = true;
	car.wheels[1].drive = false;
	car.wheels[1].brake = true;
	car.wheels[1].steering = true;

	// FRONT-RIGHT ------------------------
	car.wheels[2].connection.Set(-half_width - 0.5*wheel_width, connection_height, half_length);
	car.wheels[2].direction = direction;
	car.wheels[2].axis = axis;
	car.wheels[2].suspensionRestLength = suspensionRestLength;
	car.wheels[2].radius = wheel_radius;
	car.wheels[2].width = wheel_width;
	car.wheels[2].front = true;
	car.wheels[2].drive = false;
	car.wheels[2].brake = true;
	car.wheels[2].steering = true;

	// BACK - RIGHT ------------------------
	car.wheels[3].connection.Set(-half_width - 0.5*wheel_width, connection_height + 0.5, -half_length + wheel_radius/*half_length - wheel_radius*/);
	car.wheels[3].direction = direction;
	car.wheels[3].axis = axis;
	car.wheels[3].suspensionRestLength = suspensionRestLength;
	car.wheels[3].radius = wheel_radius;
	car.wheels[3].width = wheel_width;
	car.wheels[3].front = false;
	car.wheels[3].drive = true;
	car.wheels[3].brake = true;
	car.wheels[3].steering = false;

	vehicle = App->physics->AddVehicle(car);
	vehicle->SetPos(initial_pos.x,initial_pos.y,initial_pos.z);
	vehicle->GetTransform(IdentityMatrix.M);

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	return true;
}

// Update: draw background
update_status ModulePlayer::Update(float dt)
{
	turn = acceleration = brake = 0.0f;

	if(App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
	{
		if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_REPEAT)
		{
			if (nitro > 2) 
			{
				if (vehicle->GetKmh() < 120)
				{
					acceleration = NITRO_ACCELERATION;
					nitro -= 2;
				}
			}
		}
		else
		{
			if (vehicle->GetKmh() < 50) 
			acceleration = MAX_ACCELERATION;
		}
	}

	if(App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
	{
		if(turn < TURN_DEGREES)
			turn +=  TURN_DEGREES;
	}

	if(App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
	{
		if(turn > -TURN_DEGREES)
			turn -= TURN_DEGREES;
	}

	if(App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN)
	{
		brake = BRAKE_POWER;
	}
	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
	{
		acceleration = -MAX_ACCELERATION;
	}
	
	if (nitro < MAX_FRAMES_TURBO)
		nitro += 1;

	if (App->input->GetKey(SDL_SCANCODE_R) == KEY_UP)
	{
		vehicle->SetPos(initial_pos.x,initial_pos.y,initial_pos.z);
		vehicle->SetTransform(IdentityMatrix.M);
		brake = BRAKE_POWER;
	}
	if (App->input->GetKey(SDL_SCANCODE_T) == KEY_UP)
	{
		vehicle->SetTransform(IdentityMatrix.M);
	}

	
	vehicle->Turn(turn);
	vehicle->Brake(brake);
	vehicle->ApplyEngineForce(acceleration);

	vehicle->Render();

	char title[80];
	sprintf_s(title, "%.1f Km/h", vehicle->GetKmh());
	App->window->SetTitle(title);

	float transformation_matrix[16];
	vehicle->GetTransform(transformation_matrix);
	vec3 position(transformation_matrix[12], transformation_matrix[13], transformation_matrix[14]);


	position.x += 50;
	position.y += 20;
	position.z -= 15;
	

	return UPDATE_CONTINUE;
}



