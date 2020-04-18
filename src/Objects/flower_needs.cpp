#include "flower_needs.h"

#include "Objects/common_things.h"
#include "Sprites/sprites.h"

namespace LudumDare{

	static const int chargerSpeed=20;
	static const int degreeSpeed=15;
	static const int maxCharge=100;
	static float needsTimer=0;
	static const float maxNeedsTimer=2;
	static int minRandom=1;
	static int maxRandom=4;

	static const int recsWidth=83;
	static const int recsHeight=12;
	static const int recsY=243;
	static const int sunRecX=404;
	static const int waterRecX=46;

	static const int initialCharge=33;

	enum FlowerNeed{
		sun=1,
		water=2,
		nothing=4
	};

	FlowerNeed needs;

	Flower_Needs::Flower_Needs(){
		_sunSprite=sunSprite;
		_waterSprite=waterSprite;
		_needSunSprite=needSunSprite;
		_needWaterSprite=needWaterSprite;
		needs=nothing;
		_charging=false;
		_sunCharge=initialCharge;
		_waterCharge=initialCharge;

		_sunChargeRec.x=sunRecX;
		_sunChargeRec.y=recsY;
		_sunChargeRec.width=recsWidth;
		_sunChargeRec.height=recsHeight;

		_waterChargeRec.x=waterRecX;
		_waterChargeRec.y=recsY;
		_waterChargeRec.width=recsWidth;
		_waterChargeRec.height=recsHeight;
	}
	Flower_Needs::~Flower_Needs(){

	}
	void Flower_Needs::input(){
		if(IsKeyDown(KEY_LEFT)){
			_charging=true;
			if(needs!=water){
				_waterCharge+=chargerSpeed*GetFrameTime();
				if(_waterCharge>=maxCharge)
					_waterCharge=maxCharge;

				_sunCharge-=degreeSpeed*1.33f*GetFrameTime();
			}
			else if(needs==water){
				_waterCharge+=chargerSpeed*2*GetFrameTime();
				if(_waterCharge>=maxCharge)
					_waterCharge=maxCharge;

				_sunCharge-=degreeSpeed*GetFrameTime();
			}
		}
		else if(IsKeyDown(KEY_RIGHT)){
			_charging=true;
			if(needs!=sun){
				_sunCharge+=chargerSpeed*GetFrameTime();
				if(_sunCharge>=maxCharge)
					_sunCharge=maxCharge;

				_waterCharge-=degreeSpeed*1.33f*GetFrameTime();
			}
			else if(needs==sun){
				_sunCharge+=chargerSpeed*2*GetFrameTime();
				if(_sunCharge>=maxCharge)
					_sunCharge=maxCharge;

				_waterCharge-=degreeSpeed*GetFrameTime();
			}
		}
		else
			_charging=false;
	}
	void Flower_Needs::update(){
		if(_charging==false){
			_sunCharge-=degreeSpeed*1.33f*GetFrameTime();
			_waterCharge-=degreeSpeed*1.33f*GetFrameTime();

		}

		needsTimer+=GetFrameTime();
		if(needsTimer>=maxNeedsTimer){
			needsTimer=0;
			int need=GetRandomValue(minRandom,maxRandom);
			if(need==sun)
				needs=sun;
			else if(need==water)
				needs=water;
			else
				needs=nothing;
		}
	}
	void Flower_Needs::draw(){
		_sunChargeRec.width=(recsWidth*_sunCharge)/100;
		_waterChargeRec.width=(recsWidth*_waterCharge)/100;
		DrawRectangleRec(_sunChargeRec,YELLOW);
		DrawRectangleRec(_waterChargeRec,BLUE);
		
		DrawTexture(_sunSprite,0,0,WHITE);
		DrawTexture(_waterSprite,0,0,WHITE);

		if(needs==sun)
			DrawTexture(_needSunSprite,0,0,WHITE);
		else if(needs==water)
			DrawTexture(_needWaterSprite,0,0,WHITE);
	}
	void Flower_Needs::grow(){
		_sunCharge=initialCharge;
		_waterCharge=initialCharge;
		needs=nothing;
		maxRandom++;
	}
	bool Flower_Needs::getNeedSun(){
		if(needs==sun)
			return true;
		return false;
	}
	bool Flower_Needs::getNeedWater(){
		if(needs==water)
			return true;
		return false;
	}
	float Flower_Needs::getSunCharge(){
		return _sunCharge;
	}
	float Flower_Needs::getWaterCharge(){
		return _waterCharge;
	}
}