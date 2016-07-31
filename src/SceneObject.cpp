// SceneObject.cpp: implementation of the SceneObject class.
//
//////////////////////////////////////////////////////////////////////

#include "SceneObject.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SceneObject::SceneObject()
{
	m_bAnimated = false;
	m_bObstacle = false;
	m_bStatic = true;
	m_fHeight = 0.0;
}

SceneObject::~SceneObject()
{

}

void SceneObject::Draw()
{

}

bool SceneObject::IsObstacle()
{
	return m_bObstacle;
}

bool SceneObject::IsStatic()
{
	return m_bStatic;
}

void SceneObject::SetColor(float r, float g, float b)
{
	m_color[0] = r;
	m_color[1] = g;
	m_color[2] = b;
}

float SceneObject::GetHeight()
{
	return m_fHeight;
}

void SceneObject::InitAnimation()
{

}
