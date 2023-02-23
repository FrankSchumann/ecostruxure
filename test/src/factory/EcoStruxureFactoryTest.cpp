#include <gtest/gtest.h>

#include "factory/EcoStruxureFactory.h"
#include <core/mock/component/ComponentController.h>
#include <runtime/mock/component/RuntimeController.h>

TEST( EcoStruxureFactoryTest, Failed )
{
	GTEST_FAIL();
}

TEST( EcoStruxureFactoryTest, create )
{
    auto componentController = std::make_shared< mock::core::ComponentController >();
    auto runtimeController = std::make_shared< mock::RuntimeController >();

    EXPECT_CALL( *componentController, get( testing::_, testing::_ ) ).WillOnce( testing::Return( runtimeController ) );
    EXPECT_CALL( *runtimeController, subscribe( testing::_, testing::_ ) ).Times( testing::Exactly( 1 ) );

    EcoStruxureFactory ecoStruxureFactory = EcoStruxureFactory( componentController );

    std::string const name = std::string( "Daisy Duck" );
    auto ecoStruxure = ecoStruxureFactory.create( name );

    ASSERT_NE( nullptr, ecoStruxure );

    ASSERT_EQ( name, ecoStruxure->getName() );
    ASSERT_EQ( std::string( "EcoStruxureAdapter" ), ecoStruxure->getType() );
}

TEST( EcoStruxureFactoryTest, getType )
{
    EcoStruxureFactory ecoStruxureFactory;

    std::string const type = ecoStruxureFactory.getType();

    EXPECT_EQ( "EcoStruxureAdapter", type );
}
