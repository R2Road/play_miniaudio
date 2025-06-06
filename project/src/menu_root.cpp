#include "Menu_Root.h"

#include <string>

#include "r2tm/r2tm_MenuProcessor.h"
#include "r2tm/r2tm_VersionInfo.h"

#include "test/test_miniaudio.h"

r2tm::TitleFunctionT Menu_Root::GetTitleFunction() const
{
	return []()->const char*
	{
		static const std::string ret =
				std::string( "Root" )
			+	" | <" + r2tm::VersionInfo.String4Version + ">"
		;
		return ret.c_str();
	};
}
r2tm::DescriptionFunctionT Menu_Root::GetDescriptionFunction() const
{
	return []()->const char*
	{
		return "";
	};
}
r2tm::WriteFunctionT Menu_Root::GetWriteFunction() const
{
	return []( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', miniaudio_test::Engine_Init() );
		mp->AddItem( '2', miniaudio_test::Engine_Config() );
		mp->AddItem( '3', miniaudio_test::Engine_Volume() );
		mp->AddItem( '4', miniaudio_test::Engine_PlaySound() );
		mp->AddItem( '5', miniaudio_test::Engine_Time() );



		mp->AddLineFeed();



		mp->AddItem( 'q', miniaudio_test::Sound_Init_Load() );
		mp->AddItem( 'w', miniaudio_test::Sound_Play() );
		mp->AddItem( 'e', miniaudio_test::Sound_Duplicate() );
		mp->AddItem( 'r', miniaudio_test::Sound_Volume() );
		mp->AddItem( 't', miniaudio_test::Sound_Time() );
		mp->AddItem( 'y', miniaudio_test::Sound_FadeIn() );



		mp->AddLineFeed();



		mp->AddItem( 'a', miniaudio_test::Group_Init() );
		mp->AddItem( 's', miniaudio_test::Group_Volume() );
		mp->AddItem( 'd', miniaudio_test::Group_Time() );


		
		mp->AddSplit();



		mp->AddExit( 27 );
	};
}