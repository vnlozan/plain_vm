namespace VM {

    enum class Instruction {
        DEFAULT = 0x00,
        LITERAL = 0x01,

        SUB,
        ADD,
        INT_MUL,
        MUL,
        DIV,

        INT_EQUAL,
        SKIP, // "JUMP" if not equal for example

        SET_HEALTH,
        SET_WISDOM,
        SET_AGILITY,
        PLAY_SOUND,
        SPAWN_PARTICLES
    };
}