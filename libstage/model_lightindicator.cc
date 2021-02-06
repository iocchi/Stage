#include "stage.hh"

using namespace Stg;

ModelLightIndicator::ModelLightIndicator( World* world, 
														Model* parent,
														const std::string& type ) : 
  Model( world, parent, type ),
  m_IsOn(false),
  m_intensity_scaleFactor(0.8)
{
}


ModelLightIndicator::~ModelLightIndicator()
{
}


void ModelLightIndicator::SetState(bool isOn)
{
	m_IsOn = isOn;
}

void ModelLightIndicator::SetIntensity(double value)
{
    m_intensity_scaleFactor = value;
}


void ModelLightIndicator::ChangeColor(const std::string& cstr) {
    m_ColorStr = cstr;
	this->SetColor( Color (cstr) );
}

void ModelLightIndicator::DrawBlocks()
{
	if(m_IsOn)
	{
		Model::DrawBlocks();
	}
	else
	  {
		Color keep = this->GetColor();
		Color c = this->GetColor();
		c.r *= m_intensity_scaleFactor;
		c.g *= m_intensity_scaleFactor;
		c.b *= m_intensity_scaleFactor;
		
		this->SetColor( c );
		Model::DrawBlocks();
		
		this->SetColor( keep );
	  }
}
