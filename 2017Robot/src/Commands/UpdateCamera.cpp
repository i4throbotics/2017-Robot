#include "UpdateCamera.h"
#include "../Subsystems/Camera.h"

UpdateCamera::UpdateCamera() :
		Command() {
	Requires(Robot::camera.get());
}

void UpdateCamera::Initialize() {

}

void UpdateCamera::Execute() {
	Robot::camera->Update();
	Robot::camera->PrintValues();
	//Robot::camera->UpdatePixy();
}

bool UpdateCamera::IsFinished() {
	return false;
}

void UpdateCamera::End() {

}

void UpdateCamera::Interrupted() {

}
