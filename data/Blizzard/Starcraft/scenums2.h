
enum iscriptAnims
{
    ISCRIPT_Anim_Init,
    ISCRIPT_Anim_Death,
    ISCRIPT_Anim_GndAttkInit,
    ISCRIPT_Anim_AirAttkInit,
    ISCRIPT_Anim_Unused1,
    ISCRIPT_Anim_GndAttkRpt,
    ISCRIPT_Anim_AirAttkRpt,
    ISCRIPT_Anim_CastSpell,
    ISCRIPT_Anim_GndAttkToIdle,
    ISCRIPT_Anim_AirAttkToIdle,
    ISCRIPT_Anim_Unused2,
    ISCRIPT_Anim_Walking,
    ISCRIPT_Anim_WalkingToIdle,
    ISCRIPT_Anim_SpecialState1,
    ISCRIPT_Anim_SpecialState2,
    ISCRIPT_Anim_AlmostBuilt,
    ISCRIPT_Anim_Built,
    ISCRIPT_Anim_Landing,
    ISCRIPT_Anim_LiftOff,
    ISCRIPT_Anim_IsWorking,
    ISCRIPT_Anim_WorkingToIdle,
    ISCRIPT_Anim_WarpIn,
    ISCRIPT_Anim_Unused3,
    ISCRIPT_Anim_StarEditInit,
    ISCRIPT_Anim_Disable,
    ISCRIPT_Anim_Burrow,
    ISCRIPT_Anim_UnBurrow,
    ISCRIPT_Anim_Enable        
};

enum WPNBehaviour
{
    WPN_Behaviour_Fly,
    WPN_Behaviour_Fly_Follow_Target,
    WPN_Behaviour_Appear_on_Target_Unit,
    WPN_Behaviour_Persist_on_Target_Site,
    WPN_Behaviour_Appear_on_Target_Site,
    WPN_Behaviour_Appear_on_Attacker,
    WPN_Behaviour_Attack_Self_Destruct,
    WPN_Behaviour_Bounce,
    WPN_Behaviour_Attack_Target_Area,
    WPN_Behaviour_Max_Range
};

enum unitStatusFlags
{
 USFlag_Is_Completed = 0x1,
 USFlag_Is_on_ground__is_unit = 0x2,
 USFlag_Is_in_air = 0x4,
 USFlag_Unpowered = 0x8,
 USFlag_Burrowed = 0x10,
 USFlag_Entering_Building = 0x20,
 USFlag_Entering_Transport = 0x40,
 USFlag_Unknown0x80 = 0x80,
	
 USFlag_RequiresDetector = 0x100,
 USFlag_Cloaked = 0x200,
 USFlag_Disabled = 0x400,
 USFlag_NoCloakingEnergyDecrease = 0x800,
 USFlag_NoOrdersAllowed = 0x1000,
 USFlag_NoBrkCodeSection = 0x2000,
 USFlag_Unknown0x4000 = 0x4000,
 USFlag_CannotAttack = 0x8000,
	
 USFlag_Unknown0x10000 = 0x10000,
 USFlag_IsABuilding = 0x20000,
 USFlag_Unknown0x40000 = 0x40000,
 USFlag_Unmovable = 0x80000,

 USFlag_Invincible = 0x4000000,

 USFlag_SpeedUpgrade = 0x10000000,
 USFlag_cooldownUpgrade = 0x20000000,
 USFlag_EnergyUpgrade = 0x40000000

};

enum unitSpecialAbilityFlags
{

 USAFlag_Building = 1,
 USAFlag_Addon = 2,
 USAFlag_Flyer = 4,
 USAFlag_Worker = 8,
 USAFlag_Subunit = 0x10,
 USAFlag_Flying_Building = 0x20,
 USAFlag_Hero = 0x40,
 USAFlag_Regen_HP = 0x80,
 USAFlag_Ani_Idle = 0x100,
 USAFlag_Cloak = 0x200,
 USAFlag_2_in_1 = 0x400,
 USAFlag_Neut_Access__Neutral__Single_Entity = 0x800,
 USAFlag_Resource_Depot = 0x1000,
 USAFlag_Resource = 0x2000,
 USAFlag_Robotic = 0x4000,
 USAFlag_Detector = 0x8000,
 USAFlag_Organic = 0x10000,
 USAFlag_Creep = 0x20000,
 USAFlag_Unused = 0x40000,
 USAFlag_Req_Psi = 0x80000,
 USAFlag_Burrowable = 0x100000,
 USAFlag_Spell_Mana = 0x200000,
 USAFlag_PermaCloak = 0x400000,
 USAFlag_NPC_Access__Powerup = 0x800000,
 USAFlag_Morph_from_Unit__Check_Supply_Count = 0x1000000,
 USAFlag_Med_overlay = 0x2000000,
 USAFlag_Large_overlay = 0x4000000,
 USAFlag_Auto_attk__Battle_React = 0x8000000,
 USAFlag_Attack__Direct_attk = 0x10000000,
 USAFlag_Invincible = 0x20000000,
 USAFlag_Mech = 0x40000000,
 USAFlag_Wide_radius_creep = 0x80000000
};