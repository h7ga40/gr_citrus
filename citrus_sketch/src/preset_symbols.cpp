/*
 * mruby preset symbols
 *
 *  Copyright (C) 2018 Cores Co., Ltd. Japan
 *
 */
#include <mruby.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <mruby/array.h>
#include <mruby/compile.h>
#include <mruby/dump.h>
#include <mruby/variable.h>
#include <mruby/class.h>
#include <mruby/string.h>
#include <mruby/hash.h>
#include <mruby/range.h>
#include <mruby/data.h>
#include <mruby/proc.h>
#include <mruby/error.h>
#include <mruby/gc.h>
#include <mruby/debug.h>
#include <mruby/istruct.h>
#include <mruby/irep.h>

#ifdef MRB_USE_PRESET_SYMBOLS

KHASH_DECLARE(iv, mrb_sym, mrb_value, TRUE)
KHASH_DECLARE(n2sp, mrb_sym, mrb_sym, FALSE)

struct RFloat {
	MRB_OBJECT_HEADER;
	mrb_float f;
};

struct RCptr {
	MRB_OBJECT_HEADER;
	void *p;
};

typedef union {
	struct RBasic basic;
	struct RObject object;
	struct RClass klass;
	struct RString string;
	struct RArray array;
	struct RHash hash;
	struct RRange range;
	struct RData data;
	struct RProc proc;
	struct RException exc;
	struct RFiber fiber;
	struct REnv env;
	struct RIstruct istruct;
	struct RBreak brk;
	struct RFloat floatv;
	struct RCptr cptr;
} RVALUE;

#define PRESET_DATA __attribute__((section(".mrb_preset_data")))
extern "C" uint8_t mrb_preset_data_start[];
extern "C" uint8_t mrb_preset_data_end[];
extern "C" uint8_t data[];
extern "C" uint8_t mdata[];

#define PRESET_CONST const __attribute__((section(".mrb_preset_const")))
extern "C" uint8_t mrb_preset_const_start[];
extern "C" uint8_t mrb_preset_const_end[];

extern "C" PRESET_CONST RVALUE mrb_preset_object_0;
extern "C" PRESET_CONST RVALUE mrb_preset_object_1;
extern "C" PRESET_CONST RVALUE mrb_preset_object_2;
extern "C" PRESET_CONST RVALUE mrb_preset_object_3;
extern "C" PRESET_CONST RVALUE mrb_preset_object_4;
extern "C" PRESET_CONST RVALUE mrb_preset_object_5;
extern "C" PRESET_CONST RVALUE mrb_preset_object_6;
extern "C" PRESET_CONST RVALUE mrb_preset_object_7;
extern "C" PRESET_CONST RVALUE mrb_preset_object_8;
extern "C" PRESET_CONST RVALUE mrb_preset_object_9;
extern "C" PRESET_CONST RVALUE mrb_preset_object_10;
extern "C" PRESET_CONST RVALUE mrb_preset_object_11;
extern "C" PRESET_CONST RVALUE mrb_preset_object_12;
extern "C" PRESET_CONST RVALUE mrb_preset_object_13;
extern "C" PRESET_CONST RVALUE mrb_preset_object_14;
extern "C" PRESET_CONST RVALUE mrb_preset_object_15;
extern "C" PRESET_CONST RVALUE mrb_preset_object_16;
extern "C" PRESET_CONST RVALUE mrb_preset_object_17;
extern "C" PRESET_CONST RVALUE mrb_preset_object_18;
extern "C" PRESET_CONST RVALUE mrb_preset_object_19;
extern "C" PRESET_CONST RVALUE mrb_preset_object_20;
extern "C" PRESET_CONST RVALUE mrb_preset_object_21;
extern "C" PRESET_CONST RVALUE mrb_preset_object_22;
extern "C" PRESET_CONST RVALUE mrb_preset_object_23;
extern "C" PRESET_DATA RVALUE mrb_preset_object_24;
extern "C" PRESET_CONST RVALUE mrb_preset_object_25;
extern "C" PRESET_CONST RVALUE mrb_preset_object_26;
extern "C" PRESET_CONST RVALUE mrb_preset_object_27;
extern "C" PRESET_CONST RVALUE mrb_preset_object_28;
extern "C" PRESET_CONST RVALUE mrb_preset_object_29;
extern "C" PRESET_CONST RVALUE mrb_preset_object_30;
extern "C" PRESET_CONST RVALUE mrb_preset_object_31;
extern "C" PRESET_CONST RVALUE mrb_preset_object_32;
extern "C" PRESET_CONST RVALUE mrb_preset_object_33;
extern "C" PRESET_CONST RVALUE mrb_preset_object_34;
extern "C" PRESET_CONST RVALUE mrb_preset_object_35;
extern "C" PRESET_CONST RVALUE mrb_preset_object_36;
extern "C" PRESET_CONST RVALUE mrb_preset_object_37;
extern "C" PRESET_CONST RVALUE mrb_preset_object_38;
extern "C" PRESET_CONST RVALUE mrb_preset_object_39;
extern "C" PRESET_CONST RVALUE mrb_preset_object_40;
extern "C" PRESET_CONST RVALUE mrb_preset_object_41;
extern "C" PRESET_CONST RVALUE mrb_preset_object_42;
extern "C" PRESET_CONST RVALUE mrb_preset_object_43;
extern "C" PRESET_CONST RVALUE mrb_preset_object_44;
extern "C" PRESET_CONST RVALUE mrb_preset_object_45;
extern "C" PRESET_CONST RVALUE mrb_preset_object_46;
extern "C" PRESET_CONST RVALUE mrb_preset_object_47;
extern "C" PRESET_CONST RVALUE mrb_preset_object_48;
extern "C" PRESET_CONST RVALUE mrb_preset_object_49;
extern "C" PRESET_CONST RVALUE mrb_preset_object_50;
extern "C" PRESET_CONST RVALUE mrb_preset_object_51;
extern "C" PRESET_CONST RVALUE mrb_preset_object_52;
extern "C" PRESET_CONST RVALUE mrb_preset_object_53;
extern "C" PRESET_CONST RVALUE mrb_preset_object_54;
extern "C" PRESET_CONST RVALUE mrb_preset_object_55;
extern "C" PRESET_CONST RVALUE mrb_preset_object_56;
extern "C" PRESET_CONST RVALUE mrb_preset_object_57;
extern "C" PRESET_CONST RVALUE mrb_preset_object_58;
extern "C" PRESET_CONST RVALUE mrb_preset_object_59;
extern "C" PRESET_CONST RVALUE mrb_preset_object_60;
extern "C" PRESET_CONST RVALUE mrb_preset_object_61;
extern "C" PRESET_CONST RVALUE mrb_preset_object_62;
extern "C" PRESET_CONST RVALUE mrb_preset_object_63;
extern "C" PRESET_CONST RVALUE mrb_preset_object_64;
extern "C" PRESET_CONST RVALUE mrb_preset_object_65;
extern "C" PRESET_CONST RVALUE mrb_preset_object_66;
extern "C" PRESET_CONST RVALUE mrb_preset_object_67;
extern "C" PRESET_CONST RVALUE mrb_preset_object_68;
extern "C" PRESET_CONST RVALUE mrb_preset_object_69;
extern "C" PRESET_CONST RVALUE mrb_preset_object_70;
extern "C" PRESET_CONST RVALUE mrb_preset_object_71;
extern "C" PRESET_CONST RVALUE mrb_preset_object_72;
extern "C" PRESET_CONST RVALUE mrb_preset_object_73;
extern "C" PRESET_CONST RVALUE mrb_preset_object_74;
extern "C" PRESET_CONST RVALUE mrb_preset_object_75;
extern "C" PRESET_CONST RVALUE mrb_preset_object_76;
extern "C" PRESET_CONST RVALUE mrb_preset_object_77;
extern "C" PRESET_CONST RVALUE mrb_preset_object_78;
extern "C" PRESET_CONST RVALUE mrb_preset_object_79;
extern "C" PRESET_CONST RVALUE mrb_preset_object_80;
extern "C" PRESET_CONST RVALUE mrb_preset_object_81;
extern "C" PRESET_CONST RVALUE mrb_preset_object_82;
extern "C" PRESET_CONST RVALUE mrb_preset_object_83;
extern "C" PRESET_CONST RVALUE mrb_preset_object_84;
extern "C" PRESET_CONST RVALUE mrb_preset_object_85;
extern "C" PRESET_CONST RVALUE mrb_preset_object_86;
extern "C" PRESET_CONST RVALUE mrb_preset_object_87;
extern "C" PRESET_CONST RVALUE mrb_preset_object_88;
extern "C" PRESET_CONST RVALUE mrb_preset_object_89;
extern "C" PRESET_CONST RVALUE mrb_preset_object_90;
extern "C" PRESET_CONST RVALUE mrb_preset_object_91;
extern "C" PRESET_CONST RVALUE mrb_preset_object_92;
extern "C" PRESET_CONST RVALUE mrb_preset_object_93;
extern "C" PRESET_CONST RVALUE mrb_preset_object_94;
extern "C" PRESET_CONST RVALUE mrb_preset_object_95;
extern "C" PRESET_CONST RVALUE mrb_preset_object_96;
extern "C" PRESET_CONST RVALUE mrb_preset_object_97;
extern "C" PRESET_CONST RVALUE mrb_preset_object_98;
extern "C" PRESET_CONST RVALUE mrb_preset_object_99;
extern "C" PRESET_CONST RVALUE mrb_preset_object_100;
extern "C" PRESET_CONST RVALUE mrb_preset_object_101;
extern "C" PRESET_CONST RVALUE mrb_preset_object_102;
extern "C" PRESET_CONST RVALUE mrb_preset_object_103;
extern "C" PRESET_CONST RVALUE mrb_preset_object_104;
extern "C" PRESET_CONST RVALUE mrb_preset_object_105;
extern "C" PRESET_CONST RVALUE mrb_preset_object_106;
extern "C" PRESET_CONST RVALUE mrb_preset_object_107;
extern "C" PRESET_CONST RVALUE mrb_preset_object_108;
extern "C" PRESET_CONST RVALUE mrb_preset_object_109;
extern "C" PRESET_CONST RVALUE mrb_preset_object_110;
extern "C" PRESET_CONST RVALUE mrb_preset_object_111;
extern "C" PRESET_CONST RVALUE mrb_preset_object_112;
extern "C" PRESET_CONST RVALUE mrb_preset_object_113;
extern "C" PRESET_CONST RVALUE mrb_preset_object_114;
extern "C" PRESET_CONST RVALUE mrb_preset_object_115;
extern "C" PRESET_CONST RVALUE mrb_preset_object_116;
extern "C" PRESET_CONST RVALUE mrb_preset_object_117;
extern "C" PRESET_CONST RVALUE mrb_preset_object_118;
extern "C" PRESET_CONST RVALUE mrb_preset_object_119;
extern "C" PRESET_CONST RVALUE mrb_preset_object_120;
extern "C" PRESET_CONST RVALUE mrb_preset_object_121;
extern "C" PRESET_CONST RVALUE mrb_preset_object_122;
extern "C" PRESET_CONST RVALUE mrb_preset_object_123;
extern "C" PRESET_CONST RVALUE mrb_preset_object_124;
extern "C" PRESET_CONST RVALUE mrb_preset_object_125;
extern "C" PRESET_CONST RVALUE mrb_preset_object_126;
extern "C" PRESET_CONST RVALUE mrb_preset_object_127;
extern "C" PRESET_CONST RVALUE mrb_preset_object_128;
extern "C" PRESET_CONST RVALUE mrb_preset_object_129;
extern "C" PRESET_CONST RVALUE mrb_preset_object_130;
extern "C" PRESET_CONST RVALUE mrb_preset_object_131;
extern "C" PRESET_CONST RVALUE mrb_preset_object_132;
extern "C" PRESET_CONST RVALUE mrb_preset_object_133;
extern "C" PRESET_CONST RVALUE mrb_preset_object_134;
extern "C" PRESET_CONST RVALUE mrb_preset_object_135;
extern "C" PRESET_CONST RVALUE mrb_preset_object_136;
extern "C" PRESET_CONST RVALUE mrb_preset_object_137;
extern "C" PRESET_CONST RVALUE mrb_preset_object_138;
extern "C" PRESET_CONST RVALUE mrb_preset_object_139;
extern "C" PRESET_CONST RVALUE mrb_preset_object_140;
extern "C" PRESET_CONST RVALUE mrb_preset_object_141;
extern "C" PRESET_CONST RVALUE mrb_preset_object_142;
extern "C" PRESET_CONST RVALUE mrb_preset_object_143;
extern "C" PRESET_CONST RVALUE mrb_preset_object_144;
extern "C" PRESET_CONST RVALUE mrb_preset_object_145;
extern "C" PRESET_CONST RVALUE mrb_preset_object_146;
extern "C" PRESET_CONST RVALUE mrb_preset_object_147;
extern "C" PRESET_CONST RVALUE mrb_preset_object_148;
extern "C" PRESET_CONST RVALUE mrb_preset_object_149;
extern "C" PRESET_CONST RVALUE mrb_preset_object_150;
extern "C" PRESET_CONST RVALUE mrb_preset_object_151;
extern "C" PRESET_CONST RVALUE mrb_preset_object_152;
extern "C" PRESET_CONST RVALUE mrb_preset_object_153;
extern "C" PRESET_CONST RVALUE mrb_preset_object_154;
extern "C" PRESET_CONST RVALUE mrb_preset_object_155;
extern "C" PRESET_CONST RVALUE mrb_preset_object_156;
extern "C" PRESET_CONST RVALUE mrb_preset_object_157;
extern "C" PRESET_CONST RVALUE mrb_preset_object_158;
extern "C" PRESET_CONST RVALUE mrb_preset_object_159;
extern "C" PRESET_CONST RVALUE mrb_preset_object_160;
extern "C" PRESET_CONST RVALUE mrb_preset_object_161;
extern "C" PRESET_CONST RVALUE mrb_preset_object_162;
extern "C" PRESET_CONST RVALUE mrb_preset_object_163;
extern "C" PRESET_CONST RVALUE mrb_preset_object_164;
extern "C" PRESET_CONST RVALUE mrb_preset_object_165;
extern "C" PRESET_CONST RVALUE mrb_preset_object_166;
extern "C" PRESET_CONST RVALUE mrb_preset_object_167;
extern "C" PRESET_CONST RVALUE mrb_preset_object_168;
extern "C" PRESET_CONST RVALUE mrb_preset_object_169;
extern "C" PRESET_CONST RVALUE mrb_preset_object_170;
extern "C" PRESET_CONST RVALUE mrb_preset_object_171;
extern "C" PRESET_CONST RVALUE mrb_preset_object_172;
extern "C" PRESET_CONST RVALUE mrb_preset_object_173;
extern "C" PRESET_CONST RVALUE mrb_preset_object_174;
extern "C" PRESET_CONST RVALUE mrb_preset_object_175;
extern "C" PRESET_CONST RVALUE mrb_preset_object_176;
extern "C" PRESET_CONST RVALUE mrb_preset_object_177;
extern "C" PRESET_CONST RVALUE mrb_preset_object_178;
extern "C" PRESET_CONST RVALUE mrb_preset_object_179;
extern "C" PRESET_CONST RVALUE mrb_preset_object_180;
extern "C" PRESET_CONST RVALUE mrb_preset_object_181;
extern "C" PRESET_CONST RVALUE mrb_preset_object_182;
extern "C" PRESET_CONST RVALUE mrb_preset_object_183;
extern "C" PRESET_CONST RVALUE mrb_preset_object_184;
extern "C" PRESET_CONST RVALUE mrb_preset_object_185;
extern "C" PRESET_CONST RVALUE mrb_preset_object_186;
extern "C" PRESET_CONST RVALUE mrb_preset_object_187;
extern "C" PRESET_CONST RVALUE mrb_preset_object_188;
extern "C" PRESET_DATA RVALUE mrb_preset_object_189;
extern "C" PRESET_CONST RVALUE mrb_preset_object_190;
extern "C" PRESET_CONST RVALUE mrb_preset_object_191;
extern "C" PRESET_DATA RVALUE mrb_preset_object_192;
extern "C" PRESET_CONST RVALUE mrb_preset_object_193;
extern "C" PRESET_CONST RVALUE mrb_preset_object_194;
extern "C" PRESET_CONST RVALUE mrb_preset_object_195;
extern "C" PRESET_CONST RVALUE mrb_preset_object_196;
extern "C" PRESET_CONST RVALUE mrb_preset_object_197;
extern "C" PRESET_CONST RVALUE mrb_preset_object_198;
extern "C" PRESET_CONST RVALUE mrb_preset_object_199;
extern "C" PRESET_CONST RVALUE mrb_preset_object_200;
extern "C" PRESET_DATA RVALUE mrb_preset_object_201;
extern "C" PRESET_CONST RVALUE mrb_preset_object_202;
extern "C" PRESET_DATA RVALUE mrb_preset_object_203;
extern "C" PRESET_CONST RVALUE mrb_preset_object_204;
extern "C" PRESET_CONST RVALUE mrb_preset_object_205;
extern "C" PRESET_CONST RVALUE mrb_preset_object_206;
extern "C" PRESET_CONST RVALUE mrb_preset_object_207;
extern "C" PRESET_CONST RVALUE mrb_preset_object_208;
extern "C" PRESET_CONST RVALUE mrb_preset_object_209;
extern "C" PRESET_CONST RVALUE mrb_preset_object_210;
extern "C" PRESET_CONST RVALUE mrb_preset_object_211;
extern "C" PRESET_CONST RVALUE mrb_preset_object_212;
extern "C" PRESET_CONST RVALUE mrb_preset_object_213;
extern "C" PRESET_CONST RVALUE mrb_preset_object_214;
extern "C" PRESET_CONST RVALUE mrb_preset_object_215;
extern "C" PRESET_CONST RVALUE mrb_preset_object_216;
extern "C" PRESET_CONST RVALUE mrb_preset_object_217;
extern "C" PRESET_CONST RVALUE mrb_preset_object_218;
extern "C" PRESET_CONST RVALUE mrb_preset_object_219;
extern "C" PRESET_CONST RVALUE mrb_preset_object_220;
extern "C" PRESET_CONST RVALUE mrb_preset_object_221;
extern "C" PRESET_CONST RVALUE mrb_preset_object_222;
extern "C" PRESET_CONST RVALUE mrb_preset_object_223;
extern "C" PRESET_CONST RVALUE mrb_preset_object_224;
extern "C" PRESET_CONST RVALUE mrb_preset_object_225;
extern "C" PRESET_CONST RVALUE mrb_preset_object_226;
extern "C" PRESET_CONST RVALUE mrb_preset_object_227;
extern "C" PRESET_CONST RVALUE mrb_preset_object_228;
extern "C" PRESET_CONST RVALUE mrb_preset_object_229;
extern "C" PRESET_CONST RVALUE mrb_preset_object_230;
extern "C" PRESET_CONST RVALUE mrb_preset_object_231;
extern "C" PRESET_CONST RVALUE mrb_preset_object_232;
extern "C" PRESET_CONST RVALUE mrb_preset_object_233;
extern "C" PRESET_CONST RVALUE mrb_preset_object_234;
extern "C" PRESET_CONST RVALUE mrb_preset_object_235;
extern "C" PRESET_CONST RVALUE mrb_preset_object_236;
extern "C" PRESET_CONST RVALUE mrb_preset_object_237;
extern "C" PRESET_CONST RVALUE mrb_preset_object_238;
extern "C" PRESET_CONST RVALUE mrb_preset_object_239;
extern "C" PRESET_CONST RVALUE mrb_preset_object_240;
extern "C" PRESET_CONST RVALUE mrb_preset_object_241;
extern "C" PRESET_CONST RVALUE mrb_preset_object_242;
extern "C" PRESET_CONST RVALUE mrb_preset_object_243;
extern "C" PRESET_CONST RVALUE mrb_preset_object_244;
extern "C" PRESET_CONST RVALUE mrb_preset_object_245;
extern "C" PRESET_CONST RVALUE mrb_preset_object_246;
extern "C" PRESET_CONST RVALUE mrb_preset_object_247;
extern "C" PRESET_CONST RVALUE mrb_preset_object_248;
extern "C" PRESET_CONST RVALUE mrb_preset_object_249;
extern "C" PRESET_CONST RVALUE mrb_preset_object_250;
extern "C" PRESET_CONST RVALUE mrb_preset_object_251;
extern "C" PRESET_CONST RVALUE mrb_preset_object_252;
extern "C" PRESET_CONST RVALUE mrb_preset_object_253;
extern "C" PRESET_CONST RVALUE mrb_preset_object_254;
extern "C" PRESET_CONST RVALUE mrb_preset_object_255;
extern "C" PRESET_CONST RVALUE mrb_preset_object_256;
extern "C" PRESET_CONST RVALUE mrb_preset_object_257;
extern "C" PRESET_CONST RVALUE mrb_preset_object_258;
extern "C" PRESET_CONST RVALUE mrb_preset_object_259;
extern "C" PRESET_CONST RVALUE mrb_preset_object_260;
extern "C" PRESET_CONST RVALUE mrb_preset_object_261;
extern "C" PRESET_CONST RVALUE mrb_preset_object_262;
extern "C" PRESET_CONST RVALUE mrb_preset_object_263;
extern "C" PRESET_CONST RVALUE mrb_preset_object_264;
extern "C" PRESET_CONST RVALUE mrb_preset_object_265;
extern "C" PRESET_CONST RVALUE mrb_preset_object_266;
extern "C" PRESET_CONST RVALUE mrb_preset_object_267;
extern "C" PRESET_CONST RVALUE mrb_preset_object_268;
extern "C" PRESET_CONST RVALUE mrb_preset_object_269;
extern "C" PRESET_CONST RVALUE mrb_preset_object_270;
extern "C" PRESET_CONST RVALUE mrb_preset_object_271;
extern "C" PRESET_CONST RVALUE mrb_preset_object_272;
extern "C" PRESET_CONST RVALUE mrb_preset_object_273;
extern "C" PRESET_CONST RVALUE mrb_preset_object_274;
extern "C" PRESET_CONST RVALUE mrb_preset_object_275;
extern "C" PRESET_CONST RVALUE mrb_preset_object_276;
extern "C" PRESET_CONST RVALUE mrb_preset_object_277;
extern "C" PRESET_CONST RVALUE mrb_preset_object_278;
extern "C" PRESET_CONST RVALUE mrb_preset_object_279;
extern "C" PRESET_CONST RVALUE mrb_preset_object_280;
extern "C" PRESET_CONST RVALUE mrb_preset_object_281;
extern "C" PRESET_CONST RVALUE mrb_preset_object_282;
extern "C" PRESET_CONST RVALUE mrb_preset_object_283;
extern "C" PRESET_CONST RVALUE mrb_preset_object_284;
extern "C" PRESET_CONST RVALUE mrb_preset_object_285;
extern "C" PRESET_CONST RVALUE mrb_preset_object_286;
extern "C" PRESET_CONST RVALUE mrb_preset_object_287;
extern "C" PRESET_CONST RVALUE mrb_preset_object_288;
extern "C" PRESET_CONST RVALUE mrb_preset_object_289;
extern "C" PRESET_CONST RVALUE mrb_preset_object_290;
extern "C" PRESET_CONST RVALUE mrb_preset_object_291;
extern "C" PRESET_CONST RVALUE mrb_preset_object_292;
extern "C" PRESET_CONST RVALUE mrb_preset_object_293;
extern "C" PRESET_CONST RVALUE mrb_preset_object_294;
extern "C" PRESET_CONST RVALUE mrb_preset_object_295;
extern "C" PRESET_CONST RVALUE mrb_preset_object_296;
extern "C" PRESET_CONST RVALUE mrb_preset_object_297;
extern "C" PRESET_CONST RVALUE mrb_preset_object_298;
extern "C" PRESET_CONST RVALUE mrb_preset_object_299;
extern "C" PRESET_CONST RVALUE mrb_preset_object_300;
extern "C" PRESET_CONST RVALUE mrb_preset_object_301;
extern "C" PRESET_CONST RVALUE mrb_preset_object_302;
extern "C" PRESET_CONST RVALUE mrb_preset_object_303;
extern "C" PRESET_CONST RVALUE mrb_preset_object_304;
extern "C" PRESET_CONST RVALUE mrb_preset_object_305;
extern "C" PRESET_CONST RVALUE mrb_preset_object_306;
extern "C" PRESET_CONST RVALUE mrb_preset_object_307;
extern "C" PRESET_CONST RVALUE mrb_preset_object_308;
extern "C" PRESET_CONST RVALUE mrb_preset_object_309;
extern "C" PRESET_CONST RVALUE mrb_preset_object_310;
extern "C" PRESET_CONST RVALUE mrb_preset_object_311;
extern "C" PRESET_CONST RVALUE mrb_preset_object_312;
extern "C" PRESET_CONST RVALUE mrb_preset_object_313;
extern "C" PRESET_CONST RVALUE mrb_preset_object_314;
extern "C" PRESET_CONST RVALUE mrb_preset_object_315;
extern "C" PRESET_CONST RVALUE mrb_preset_object_316;
extern "C" PRESET_CONST RVALUE mrb_preset_object_317;
extern "C" PRESET_CONST RVALUE mrb_preset_object_318;
extern "C" PRESET_CONST RVALUE mrb_preset_object_319;
extern "C" PRESET_CONST RVALUE mrb_preset_object_320;
extern "C" PRESET_CONST RVALUE mrb_preset_object_321;
extern "C" PRESET_CONST RVALUE mrb_preset_object_322;
extern "C" PRESET_CONST RVALUE mrb_preset_object_323;
extern "C" PRESET_CONST RVALUE mrb_preset_object_324;
extern "C" PRESET_CONST RVALUE mrb_preset_object_325;
extern "C" PRESET_CONST RVALUE mrb_preset_object_326;
extern "C" PRESET_CONST RVALUE mrb_preset_object_327;
extern "C" PRESET_CONST RVALUE mrb_preset_object_328;
extern "C" PRESET_CONST RVALUE mrb_preset_object_329;
extern "C" PRESET_CONST RVALUE mrb_preset_object_330;
extern "C" PRESET_CONST RVALUE mrb_preset_object_331;
extern "C" PRESET_CONST RVALUE mrb_preset_object_332;
extern "C" PRESET_CONST RVALUE mrb_preset_object_333;

extern "C" PRESET_CONST mrb_irep mrb_preset_irep_0;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_1;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_2;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_3;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_4;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_5;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_6;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_7;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_8;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_9;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_10;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_11;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_12;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_13;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_14;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_15;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_16;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_17;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_18;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_19;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_20;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_21;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_22;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_23;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_24;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_25;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_26;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_27;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_28;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_29;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_30;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_31;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_32;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_33;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_34;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_35;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_36;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_37;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_38;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_39;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_40;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_41;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_42;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_43;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_44;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_45;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_46;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_47;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_48;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_49;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_50;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_51;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_52;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_53;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_54;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_55;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_56;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_57;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_58;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_59;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_60;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_61;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_62;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_63;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_64;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_65;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_66;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_67;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_68;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_69;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_70;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_71;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_72;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_73;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_74;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_75;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_76;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_77;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_78;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_79;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_80;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_81;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_82;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_83;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_84;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_85;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_86;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_87;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_88;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_89;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_90;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_91;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_92;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_93;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_94;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_95;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_96;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_97;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_98;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_99;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_100;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_101;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_102;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_103;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_104;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_105;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_106;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_107;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_108;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_109;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_110;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_111;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_112;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_113;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_114;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_115;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_116;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_117;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_118;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_119;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_120;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_121;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_122;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_123;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_124;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_125;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_126;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_127;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_128;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_129;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_130;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_131;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_132;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_133;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_134;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_135;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_136;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_137;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_138;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_139;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_140;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_141;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_142;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_143;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_144;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_145;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_146;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_147;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_148;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_149;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_150;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_151;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_152;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_153;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_154;
extern "C" PRESET_CONST mrb_irep mrb_preset_irep_155;

extern "C" mrb_value gc_disable(mrb_state *mrb, mrb_value self);
extern "C" mrb_value gc_enable(mrb_state *mrb, mrb_value self);
extern "C" mrb_value gc_generational_mode_get(mrb_state *mrb, mrb_value self);
extern "C" mrb_value gc_generational_mode_set(mrb_state *mrb, mrb_value self);
extern "C" mrb_value gc_interval_ratio_get(mrb_state *mrb, mrb_value self);
extern "C" mrb_value gc_interval_ratio_set(mrb_state *mrb, mrb_value self);
extern "C" mrb_value gc_start(mrb_state *mrb, mrb_value self);
extern "C" mrb_value gc_step_ratio_get(mrb_state *mrb, mrb_value self);
extern "C" mrb_value gc_step_ratio_set(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_sym_to_s(mrb_state *mrb, mrb_value self);
extern "C" mrb_value sym_cmp(mrb_state *mrb, mrb_value self);
extern "C" mrb_value sym_equal(mrb_state *mrb, mrb_value self);
extern "C" mrb_value sym_inspect(mrb_state *mrb, mrb_value self);
extern "C" mrb_value sym_to_sym(mrb_state *mrb, mrb_value self);
extern "C" mrb_value attr_reader(mrb_state *mrb, mrb_value self);
extern "C" mrb_value attr_writer(mrb_state *mrb, mrb_value self);
extern "C" mrb_value inspect_main(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mod_define_method(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_bob_init(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_bob_not(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_class_initialize(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_class_new_class(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_class_superclass(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_instance_new(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_mod_alias(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_mod_ancestors(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_mod_append_features(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_mod_attr_reader(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_mod_attr_writer(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_mod_const_defined(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_mod_const_get(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_mod_const_missing(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_mod_const_set(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_mod_cvar_defined(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_mod_cvar_get(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_mod_cvar_set(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_mod_eqq(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_mod_extend_object(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_mod_include_p(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_mod_included_modules(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_mod_initialize(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_mod_instance_methods(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_mod_method_defined(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_mod_module_function(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_mod_prepend_features(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_mod_remove_const(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_mod_remove_cvar(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_mod_remove_method(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_mod_s_constants(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_mod_to_s(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_mod_undef(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_obj_equal_m(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_obj_not_equal_m(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_singleton_class(mrb_state *mrb, mrb_value self);
extern "C" mrb_value top_define_method(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_aref_m(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_bytes(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_bytesize(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_capitalize(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_capitalize_bang(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_chomp(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_chomp_bang(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_chop(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_chop_bang(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_cmp_m(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_downcase(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_downcase_bang(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_dump(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_empty_p(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_eql(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_equal_m(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_hash_m(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_include(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_index_m(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_init(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_inspect(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_intern(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_plus_m(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_replace(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_reverse(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_reverse_bang(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_rindex(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_size(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_split_m(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_times(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_to_f(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_to_i(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_to_s(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_upcase(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_upcase_bang(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_f_send(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_mod_module_eval(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_mod_s_nesting(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_obj_instance_eval(mrb_state *mrb, mrb_value self);
extern "C" mrb_value false_and(mrb_state *mrb, mrb_value self);
extern "C" mrb_value false_xor(mrb_state *mrb, mrb_value self);
extern "C" mrb_value false_to_s(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_any_to_s(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_true(mrb_state *mrb, mrb_value self);
extern "C" mrb_value nil_inspect(mrb_state *mrb, mrb_value self);
extern "C" mrb_value nil_to_s(mrb_state *mrb, mrb_value self);
extern "C" mrb_value true_to_s(mrb_state *mrb, mrb_value self);
extern "C" mrb_value true_xor(mrb_state *mrb, mrb_value self);
extern "C" mrb_value exc_exception(mrb_state *mrb, mrb_value self);
extern "C" mrb_value exc_initialize(mrb_state *mrb, mrb_value self);
extern "C" mrb_value exc_inspect(mrb_state *mrb, mrb_value self);
extern "C" mrb_value exc_message(mrb_state *mrb, mrb_value self);
extern "C" mrb_value exc_set_backtrace(mrb_state *mrb, mrb_value self);
extern "C" mrb_value exc_to_s(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_ary_aget(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_ary_aset(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_ary_clear(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_ary_cmp(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_ary_concat_m(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_ary_delete_at(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_ary_empty_p(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_ary_eq(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_ary_first(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_ary_index_m(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_ary_join_m(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_ary_last(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_ary_plus(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_ary_pop(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_ary_push_m(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_ary_replace_m(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_ary_reverse(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_ary_reverse_bang(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_ary_rindex_m(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_ary_s_create(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_ary_shift(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_ary_size(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_ary_svalue(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_ary_times(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_ary_unshift_m(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_f_global_variables(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_mod_class_variables(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_mod_constants(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_obj_instance_variables(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_hash_aget(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_hash_aset(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_hash_clear(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_hash_default(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_hash_default_proc(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_hash_delete(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_hash_dup(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_hash_empty_p(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_hash_has_key(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_hash_has_value(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_hash_init(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_hash_keys(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_hash_set_default(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_hash_set_default_proc(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_hash_shift(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_hash_size_m(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_hash_values(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mod_define_singleton_method(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_equal_m(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_f_block_given_p_m(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_f_raise(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_krn_class_defined(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_local_variables(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_obj_ceqq(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_obj_class_m(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_obj_clone(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_obj_dup(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_obj_extend_m(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_obj_freeze(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_obj_frozen(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_obj_hash(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_obj_init_copy(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_obj_inspect(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_obj_is_kind_of_m(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_obj_ivar_defined(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_obj_ivar_get(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_obj_ivar_set(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_obj_public_methods(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_obj_private_methods(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_obj_protected_methods(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_obj_remove_instance_variable(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_obj_singleton_methods_m(mrb_state *mrb, mrb_value self);
extern "C" mrb_value obj_is_instance_of(mrb_state *mrb, mrb_value self);
extern "C" mrb_value obj_respond_to(mrb_state *mrb, mrb_value self);
extern "C" mrb_value fix_and(mrb_state *mrb, mrb_value self);
extern "C" mrb_value fix_divmod(mrb_state *mrb, mrb_value self);
extern "C" mrb_value fix_eql(mrb_state *mrb, mrb_value self);
extern "C" mrb_value fix_equal(mrb_state *mrb, mrb_value self);
extern "C" mrb_value fix_lshift(mrb_state *mrb, mrb_value self);
extern "C" mrb_value fix_minus(mrb_state *mrb, mrb_value self);
extern "C" mrb_value fix_mod(mrb_state *mrb, mrb_value self);
extern "C" mrb_value fix_mul(mrb_state *mrb, mrb_value self);
extern "C" mrb_value fix_or(mrb_state *mrb, mrb_value self);
extern "C" mrb_value fix_plus(mrb_state *mrb, mrb_value self);
extern "C" mrb_value fix_rev(mrb_state *mrb, mrb_value self);
extern "C" mrb_value fix_rshift(mrb_state *mrb, mrb_value self);
extern "C" mrb_value fix_to_f(mrb_state *mrb, mrb_value self);
extern "C" mrb_value fix_to_s(mrb_state *mrb, mrb_value self);
extern "C" mrb_value fix_xor(mrb_state *mrb, mrb_value self);
extern "C" mrb_value flo_and(mrb_state *mrb, mrb_value self);
extern "C" mrb_value flo_ceil(mrb_state *mrb, mrb_value self);
extern "C" mrb_value flo_divmod(mrb_state *mrb, mrb_value self);
extern "C" mrb_value flo_eq(mrb_state *mrb, mrb_value self);
extern "C" mrb_value flo_eql(mrb_state *mrb, mrb_value self);
extern "C" mrb_value flo_finite_p(mrb_state *mrb, mrb_value self);
extern "C" mrb_value flo_floor(mrb_state *mrb, mrb_value self);
extern "C" mrb_value flo_infinite_p(mrb_state *mrb, mrb_value self);
extern "C" mrb_value flo_lshift(mrb_state *mrb, mrb_value self);
extern "C" mrb_value flo_minus(mrb_state *mrb, mrb_value self);
extern "C" mrb_value flo_mod(mrb_state *mrb, mrb_value self);
extern "C" mrb_value flo_mul(mrb_state *mrb, mrb_value self);
extern "C" mrb_value flo_nan_p(mrb_state *mrb, mrb_value self);
extern "C" mrb_value flo_or(mrb_state *mrb, mrb_value self);
extern "C" mrb_value flo_plus(mrb_state *mrb, mrb_value self);
extern "C" mrb_value flo_rev(mrb_state *mrb, mrb_value self);
extern "C" mrb_value flo_round(mrb_state *mrb, mrb_value self);
extern "C" mrb_value flo_rshift(mrb_state *mrb, mrb_value self);
extern "C" mrb_value flo_to_s(mrb_state *mrb, mrb_value self);
extern "C" mrb_value flo_truncate(mrb_state *mrb, mrb_value self);
extern "C" mrb_value flo_xor(mrb_state *mrb, mrb_value self);
extern "C" mrb_value num_cmp(mrb_state *mrb, mrb_value self);
extern "C" mrb_value num_div(mrb_state *mrb, mrb_value self);
extern "C" mrb_value num_finite_p(mrb_state *mrb, mrb_value self);
extern "C" mrb_value num_ge(mrb_state *mrb, mrb_value self);
extern "C" mrb_value num_gt(mrb_state *mrb, mrb_value self);
extern "C" mrb_value num_infinite_p(mrb_state *mrb, mrb_value self);
extern "C" mrb_value num_le(mrb_state *mrb, mrb_value self);
extern "C" mrb_value num_lt(mrb_state *mrb, mrb_value self);
extern "C" mrb_value num_pow(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_proc_arity(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_proc_init_copy(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_proc_s_new(mrb_state *mrb, mrb_value self);
extern "C" mrb_value proc_lambda(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_range_beg(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_range_end(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_range_eq(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_range_excl(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_range_include(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_range_initialize(mrb_state *mrb, mrb_value self);
extern "C" mrb_value range_eql(mrb_state *mrb, mrb_value self);
extern "C" mrb_value range_initialize_copy(mrb_state *mrb, mrb_value self);
extern "C" mrb_value range_inspect(mrb_state *mrb, mrb_value self);
extern "C" mrb_value range_to_s(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_exc_backtrace(mrb_state *mrb, mrb_value self);
extern "C" mrb_value math_acos(mrb_state *mrb, mrb_value self);
extern "C" mrb_value math_acosh(mrb_state *mrb, mrb_value self);
extern "C" mrb_value math_asin(mrb_state *mrb, mrb_value self);
extern "C" mrb_value math_asinh(mrb_state *mrb, mrb_value self);
extern "C" mrb_value math_atan(mrb_state *mrb, mrb_value self);
extern "C" mrb_value math_atan2(mrb_state *mrb, mrb_value self);
extern "C" mrb_value math_atanh(mrb_state *mrb, mrb_value self);
extern "C" mrb_value math_cbrt(mrb_state *mrb, mrb_value self);
extern "C" mrb_value math_cos(mrb_state *mrb, mrb_value self);
extern "C" mrb_value math_cosh(mrb_state *mrb, mrb_value self);
extern "C" mrb_value math_erf(mrb_state *mrb, mrb_value self);
extern "C" mrb_value math_erfc(mrb_state *mrb, mrb_value self);
extern "C" mrb_value math_exp(mrb_state *mrb, mrb_value self);
extern "C" mrb_value math_frexp(mrb_state *mrb, mrb_value self);
extern "C" mrb_value math_hypot(mrb_state *mrb, mrb_value self);
extern "C" mrb_value math_ldexp(mrb_state *mrb, mrb_value self);
extern "C" mrb_value math_log(mrb_state *mrb, mrb_value self);
extern "C" mrb_value math_log10(mrb_state *mrb, mrb_value self);
extern "C" mrb_value math_log2(mrb_state *mrb, mrb_value self);
extern "C" mrb_value math_sin(mrb_state *mrb, mrb_value self);
extern "C" mrb_value math_sinh(mrb_state *mrb, mrb_value self);
extern "C" mrb_value math_sqrt(mrb_state *mrb, mrb_value self);
extern "C" mrb_value math_tan(mrb_state *mrb, mrb_value self);
extern "C" mrb_value math_tanh(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_int_allbits(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_int_anybits(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_int_chr(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_int_nobits(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_fixnum_chr(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_byteslice(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_chr(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_concat_m(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_del_prefix(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_del_prefix_bang(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_del_suffix(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_del_suffix_bang(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_end_with(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_getbyte(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_hex(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_lines(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_oct(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_ord(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_setbyte(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_start_with(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_succ(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_succ_bang(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_swapcase(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_swapcase_bang(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_str_upto(mrb_state *mrb, mrb_value self);
extern "C" mrb_value fiber_current(mrb_state *mrb, mrb_value self);
extern "C" mrb_value fiber_eq(mrb_state *mrb, mrb_value self);
extern "C" mrb_value fiber_init(mrb_state *mrb, mrb_value self);
extern "C" mrb_value fiber_resume(mrb_state *mrb, mrb_value self);
extern "C" mrb_value fiber_transfer(mrb_state *mrb, mrb_value self);
extern "C" mrb_value fiber_yield(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_fiber_alive_p(mrb_state *mrb, mrb_value self);
extern "C" mrb_value mrb_f_sprintf(mrb_state *mrb, mrb_value self);
extern "C" uint8_t mrblib_irep[];
extern "C" uint8_t gem_mrblib_irep_mruby_numeric_ext[];
extern "C" uint8_t gem_mrblib_irep_mruby_string_ext[];
extern "C" uint8_t gem_mrblib_irep_mruby_sprintf[];
extern "C" uint8_t call_iseq[];

const char *const mrb_preset_symbols[] = {
	"__attached__",
	"BasicObject",
	"Object",
	"Module",
	"Class",
	"__classname__",
	"Proc",
	"initialize",
	"!",
	"==",
	"!=",
	"__id__",
	"__send__",
	"instance_eval",
	"new",
	"superclass",
	"inherited",
	"class_variable_defined?",
	"class_variable_get",
	"class_variable_set",
	"extend_object",
	"extended",
	"prepended",
	"prepend_features",
	"include?",
	"append_features",
	"class_eval",
	"included",
	"included_modules",
	"instance_methods",
	"method_defined?",
	"module_eval",
	"module_function",
	"private",
	"protected",
	"public",
	"remove_class_variable",
	"remove_method",
	"method_removed",
	"attr_reader",
	"attr_writer",
	"to_s",
	"inspect",
	"alias_method",
	"ancestors",
	"undef_method",
	"const_defined?",
	"const_get",
	"const_set",
	"constants",
	"remove_const",
	"const_missing",
	"define_method",
	"class_variables",
	"===",
	"nesting",
	"NilClass",
	"&",
	"^",
	"|",
	"nil?",
	"TrueClass",
	"FalseClass",
	"Kernel",
	"block_given?",
	"global_variables",
	"iterator?",
	"local_variables",
	"raise",
	"singleton_class",
	"class",
	"clone",
	"dup",
	"eql?",
	"equal?",
	"extend",
	"freeze",
	"frozen?",
	"hash",
	"initialize_copy",
	"instance_of?",
	"instance_variable_defined?",
	"instance_variable_get",
	"instance_variable_set",
	"instance_variables",
	"is_a?",
	"kind_of?",
	"methods",
	"object_id",
	"private_methods",
	"protected_methods",
	"public_methods",
	"remove_instance_variable",
	"respond_to?",
	"send",
	"singleton_methods",
	"define_singleton_method",
	"__case_eqq",
	"class_defined?",
	"Comparable",
	"Enumerable",
	"Symbol",
	"id2name",
	"to_sym",
	"<=>",
	"String",
	"bytesize",
	"+",
	"*",
	"[]",
	"capitalize",
	"capitalize!",
	"chomp",
	"chomp!",
	"chop",
	"chop!",
	"downcase",
	"downcase!",
	"empty?",
	"index",
	"intern",
	"length",
	"replace",
	"reverse",
	"reverse!",
	"rindex",
	"size",
	"slice",
	"split",
	"to_f",
	"to_i",
	"to_str",
	"upcase",
	"upcase!",
	"bytes",
	"Exception",
	"exception",
	"message",
	"backtrace",
	"set_backtrace",
	"StandardError",
	"RuntimeError",
	"ScriptError",
	"SyntaxError",
	"SystemStackError",
	"mesg",
	"NoMemoryError",
	"arity",
	"call",
	"lambda",
	"Array",
	"<<",
	"[]=",
	"clear",
	"concat",
	"delete_at",
	"first",
	"join",
	"last",
	"pop",
	"push",
	"append",
	"shift",
	"unshift",
	"prepend",
	"__ary_eq",
	"__ary_cmp",
	"__ary_index",
	"__svalue",
	"Hash",
	"default",
	"default=",
	"default_proc",
	"default_proc=",
	"__delete",
	"has_key?",
	"has_value?",
	"key?",
	"keys",
	"member?",
	"store",
	"value?",
	"values",
	"to_hash",
	"Numeric",
	"**",
	"/",
	"quo",
	"<",
	"<=",
	">",
	">=",
	"finite?",
	"infinite?",
	"Integer",
	"to_int",
	"ceil",
	"floor",
	"round",
	"truncate",
	"Fixnum",
	"-",
	"%",
	"~",
	">>",
	"divmod",
	"Float",
	"nan?",
	"INFINITY",
	"NAN",
	"Integral",
	"Range",
	"begin",
	"end",
	"exclude_end?",
	"GC",
	"start",
	"enable",
	"disable",
	"interval_ratio",
	"interval_ratio=",
	"step_ratio",
	"step_ratio=",
	"generational_mode=",
	"generational_mode",
	"RUBY_VERSION",
	"RUBY_ENGINE",
	"RUBY_ENGINE_VERSION",
	"MRUBY_VERSION",
	"MRUBY_RELEASE_NO",
	"MRUBY_RELEASE_DATE",
	"MRUBY_DESCRIPTION",
	"MRUBY_COPYRIGHT",
	"ArgumentError",
	"LocalJumpError",
	"RangeError",
	"FloatDomainError",
	"RegexpError",
	"TypeError",
	"NameError",
	"NoMethodError",
	"IndexError",
	"KeyError",
	"NotImplementedError",
	"FrozenError",
	"StopIteration",
	"attr_accessor",
	"attr",
	"include",
	"each",
	"name",
	"@name",
	"args",
	"@args",
	"result",
	"each_index",
	"collect!",
	"map!",
	"_inspect",
	"delete",
	"to_enum",
	"map",
	"__sort_sub__",
	"sort!",
	"sort",
	"between?",
	"all?",
	"any?",
	"collect",
	"detect",
	"each_with_index",
	"entries",
	"find",
	"find_all",
	"grep",
	"inject",
	"reduce",
	"max",
	"min",
	"partition",
	"reject",
	"select",
	"to_a",
	"each_key",
	"each_value",
	"merge",
	"reject!",
	"select!",
	"rehash",
	"__update",
	"`",
	"loop",
	"!~",
	"=~",
	"+@",
	"-@",
	"abs",
	"downto",
	"next",
	"succ",
	"times",
	"upto",
	"step",
	"each_line",
	"__sub_replace",
	"gsub",
	"gsub!",
	"scan",
	"sub",
	"sub!",
	"each_char",
	"each_byte",
	"match",
	"Regexp",
	"names",
	"m",
	"block",
	"idx",
	"len",
	"obj",
	"x",
	"other",
	"i",
	"n",
	"key",
	"ret",
	"left",
	"right",
	"j",
	"pivot",
	"tmp",
	"cmp",
	"val",
	"ary",
	"ifnone",
	"pattern",
	"sv",
	"sym",
	"flag",
	"y",
	"ary_T",
	"ary_F",
	"h",
	"e",
	"k",
	"v",
	"vals",
	"s",
	"a",
	"num",
	"lim",
	"str_each",
	"rs",
	"offset",
	"rs_len",
	"this",
	"pos",
	"pre",
	"post",
	"t",
	"plen",
	"found",
	"str",
	"reg",
	"anum",
	"value",
	"posnum",
	"b",
	"head",
	"tail",
	"re",
	"r",
	"name=",
	"@result",
	"result=",
	"Math",
	"DomainError",
	"PI",
	"E",
	"TOLERANCE",
	"sin",
	"cos",
	"tan",
	"asin",
	"acos",
	"atan",
	"atan2",
	"sinh",
	"cosh",
	"tanh",
	"asinh",
	"acosh",
	"atanh",
	"exp",
	"log",
	"log2",
	"log10",
	"sqrt",
	"cbrt",
	"frexp",
	"ldexp",
	"hypot",
	"erf",
	"erfc",
	"chr",
	"allbits?",
	"anybits?",
	"nobits?",
	"div",
	"zero?",
	"nonzero?",
	"positive?",
	"negative?",
	"dump",
	"getbyte",
	"setbyte",
	"byteslice",
	"swapcase!",
	"swapcase",
	"start_with?",
	"end_with?",
	"hex",
	"oct",
	"lines",
	"succ!",
	"next!",
	"ord",
	"delete_prefix!",
	"delete_prefix",
	"delete_suffix!",
	"delete_suffix",
	"try_convert",
	"lstrip",
	"rstrip",
	"strip",
	"lstrip!",
	"rstrip!",
	"strip!",
	"casecmp",
	"casecmp?",
	"rpartition",
	"slice!",
	"insert",
	"ljust",
	"rjust",
	"chars",
	"codepoints",
	"each_codepoint",
	"z",
	"c",
	"sep",
	"arg1",
	"arg2",
	"validated",
	"beg",
	"ed",
	"str2",
	"idx2",
	"padstr",
	"pad_repetitions",
	"padding",
	"arg",
	"sprintf",
	"format",
	"Fiber",
	"resume",
	"transfer",
	"alive?",
	"yield",
	"current",
	"FiberError",
};

const int mrb_preset_symbols_count = (sizeof(mrb_preset_symbols) / sizeof(mrb_preset_symbols[0]));

const char mrb_preset_strings_0[] = "can't modify frozen Strin";
const char mrb_preset_strings_1[] = "String#match needs Regexp clas";
const char mrb_preset_strings_2[] = " \x0C\n\r\t";
const char mrb_preset_strings_3[] = "wrong number of arguments (given";
const char mrb_preset_strings_4[] = ", expected 2";
const char mrb_preset_strings_5[] = "scan not available (yet";
const char mrb_preset_strings_6[] = "";
const char mrb_preset_strings_7[] = "";
const char mrb_preset_strings_8[] = "";
const char mrb_preset_strings_9[] = "";
const char mrb_preset_strings_10[] = "";
const char mrb_preset_strings_11[] = "";
const char mrb_preset_strings_12[] = "";
const char mrb_preset_strings_13[] = "";
const char mrb_preset_strings_14[] = "";
const char mrb_preset_strings_15[] = "";
const char mrb_preset_strings_16[] = "";
const char mrb_preset_strings_17[] = "";
const char mrb_preset_strings_18[] = "";
const char mrb_preset_strings_19[] = "";
const char mrb_preset_strings_20[] = "";
const char mrb_preset_strings_21[] = "type mismatch:";
const char mrb_preset_strings_22[] = " give";
const char mrb_preset_strings_23[] = "wrong number of arguments (for 1..2";
const char mrb_preset_strings_24[] = "string not matche";
const char mrb_preset_strings_25[] = "index";
const char mrb_preset_strings_26[] = " out of strin";
const char mrb_preset_strings_27[] = "negative length";
const char mrb_preset_strings_28[] = " for 2..3";
const char mrb_preset_strings_29[] = "zero width paddin";
const char mrb_preset_strings_30[] = "type mismatch: String give";
const char mrb_preset_strings_31[] = "comparison of";
const char mrb_preset_strings_32[] = " with";
const char mrb_preset_strings_33[] = " faile";
const char mrb_preset_strings_34[] = "[";
const char mrb_preset_strings_35[] = "";
const char mrb_preset_strings_36[] = "[...";
const char mrb_preset_strings_37[] = "expected Integer for 1st argumen";
const char mrb_preset_strings_38[] = "negative array siz";
const char mrb_preset_strings_39[] = "too many argument";
const char mrb_preset_strings_40[] = "can't convert argument into Has";
const char mrb_preset_strings_41[] = "{...";
const char mrb_preset_strings_42[] = "{";
const char mrb_preset_strings_43[] = "";
const char mrb_preset_strings_44[] = "=";
const char mrb_preset_strings_45[] = "step can't be ";
const char mrb_preset_strings_46[] = "Floa";
const char mrb_preset_strings_47[] = "can't iterat";
const char mrb_preset_strings_48[] = "2018-4-2";
const char mrb_preset_strings_49[] = "Math::DomainErro";
const char mrb_preset_strings_50[] = "1.4.";
const char mrb_preset_strings_51[] = "fiber required for enumerato";
const char mrb_preset_strings_52[] = "backquotes not implemente";
const char mrb_preset_strings_53[] = "1.";
const char mrb_preset_strings_54[] = "mrub";
const char mrb_preset_strings_55[] = "mruby 1.4.1 (2018-4-27)";
const char mrb_preset_strings_56[] = "mruby - Copyright (c) 2010-2018 mruby developer";
const char mrb_preset_strings_57[] = "Out of memor";
const char mrb_preset_strings_58[] = "stack level too dee";
const char mrb_preset_strings_59[] = "arena overflow erro";

const uint8_t n2s_tbl_ed_flags[] = {
	0xa2, 0x28, 0xa0, 0x28, 0x82, 0x8a, 0xaa, 0x22, 0x80, 0x80, 0x02, 0x00, 0x80, 0x2a, 0xa8, 0x80,
	0x88, 0x00, 0x28, 0x08, 0x88, 0xa8, 0x2a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x88, 0x08, 0x0a, 0x02, 0x00, 0x20, 0x2a, 0x20, 0x80, 0xaa, 0x00, 0x82, 0x02, 0xaa, 0xaa, 0x08,
	0xa0, 0xaa, 0xa8, 0x28, 0x82, 0x02, 0x20, 0x80, 0xa2, 0x02, 0x8a, 0x82, 0xaa, 0x08, 0x0a, 0xa0,
	0xa8, 0x02, 0xa2, 0x0a, 0x88, 0x20, 0x28, 0x02, 0x00, 0x8a, 0x02, 0x80, 0xa8, 0x0a, 0x22, 0x8a,
	0xa8, 0x8a, 0xa8, 0x2a, 0xaa, 0xaa, 0xa0, 0x80, 0xaa, 0x08, 0xa2, 0x8a, 0x80, 0xa2, 0xa0, 0x2a,
	0x0a, 0x08, 0x02, 0x00, 0x82, 0xa8, 0xa2, 0x0a, 0x28, 0xa2, 0x2a, 0xaa, 0x28, 0x88, 0xa0, 0xaa,
	0x20, 0xa2, 0xaa, 0x88, 0xa2, 0xa2, 0xaa, 0xaa, 0xa0, 0x8a, 0xaa, 0xa8, 0xa2, 0x20, 0xa2, 0x2a,
	0xa2, 0x0a, 0xa0, 0x8a, 0xaa, 0xa0, 0x2a, 0x00, 0x80, 0x82, 0x88, 0xa8, 0x22, 0xa0, 0xa2, 0xa0,
	0x00, 0xa0, 0xaa, 0x80, 0x82, 0x08, 0xaa, 0x0a, 0x28, 0xa2, 0xa0, 0xa2, 0xa2, 0xaa, 0x0a, 0x82,
	0xa0, 0xa8, 0x0a, 0x28, 0xa0, 0x08, 0xa8, 0x02, 0x22, 0x80, 0x8a, 0xaa, 0x88, 0xa0, 0xa0, 0x82,
	0xaa, 0x28, 0x28, 0x80, 0x82, 0x88, 0x88, 0x82, 0x82, 0x88, 0x00, 0xa0, 0x2a, 0xaa, 0x20, 0x0a,
	0x08, 0x80, 0xa2, 0x2a, 0x08, 0x28, 0x08, 0xa0, 0x80, 0xaa, 0xa0, 0x2a, 0x2a, 0xaa, 0xaa, 0xaa,
	0x2a, 0x00, 0xa0, 0x2a, 0x2a, 0xaa, 0xa8, 0x2a, 0x8a, 0xaa, 0xaa, 0x28, 0x80, 0x82, 0xaa, 0x8a,
	0x80, 0x00, 0x20, 0x02, 0xa0, 0x88, 0xaa, 0x22, 0x00, 0x00, 0x88, 0x0a, 0x8a, 0xaa, 0xaa, 0x2a,
	0x80, 0x20, 0xa8, 0xa2, 0x2a, 0x82, 0x2a, 0x80, 0xa0, 0xa2, 0x00, 0x80, 0xaa, 0x2a, 0xaa, 0xaa,
};
const mrb_sym n2s_tbl_keys[] = {
	0, 127, 0, 0, 21, 0, 0, 138, 327, 438, 0, 0, 198, 0, 0, 145,
	0, 220, 461, 0, 0, 0, 439, 0, 0, 0, 0, 0, 0, 255, 0, 263,
	229, 9, 91, 0, 457, 203, 58, 0, 0, 174, 109, 108, 196, 202, 466, 136,
	187, 106, 342, 0, 0, 0, 0, 257, 286, 0, 0, 0, 11, 189, 191, 0,
	341, 0, 330, 0, 70, 176, 261, 227, 379, 0, 0, 33, 133, 0, 61, 137,
	370, 0, 184, 0, 65, 0, 0, 0, 0, 0, 0, 168, 430, 64, 59, 445,
	291, 349, 217, 287, 1, 344, 397, 374, 343, 323, 62, 135, 345, 316, 324, 431,
	329, 368, 297, 348, 360, 372, 242, 346, 321, 306, 48, 449, 60, 293, 204, 340,
	460, 0, 163, 0, 455, 0, 312, 450, 0, 0, 52, 451, 0, 317, 416, 82,
	272, 409, 119, 354, 364, 387, 0, 25, 0, 0, 0, 452, 453, 55, 0, 456,
	359, 326, 471, 0, 0, 0, 0, 0, 249, 213, 290, 194, 0, 23, 405, 0,
	0, 230, 47, 367, 0, 0, 0, 0, 0, 0, 0, 0, 28, 0, 139, 169,
	228, 459, 0, 0, 0, 0, 0, 0, 393, 0, 0, 0, 465, 0, 0, 442,
	0, 206, 120, 0, 0, 247, 259, 384, 222, 381, 0, 214, 216, 105, 253, 0,
	0, 181, 0, 0, 0, 180, 147, 390, 0, 0, 246, 0, 0, 2, 182, 0,
	0, 0, 0, 0, 31, 0, 90, 320, 0, 0, 100, 210, 38, 282, 0, 0,
	45, 0, 0, 0, 0, 197, 115, 241, 0, 107, 0, 0, 0, 0, 79, 233,
	447, 0, 468, 0, 256, 458, 0, 271, 331, 0, 0, 153, 0, 212, 195, 225,
	254, 140, 183, 398, 0, 0, 423, 0, 0, 314, 158, 141, 234, 269, 170, 0,
	142, 0, 0, 0, 0, 0, 134, 266, 0, 22, 0, 428, 0, 0, 418, 0,
	186, 0, 0, 0, 0, 0, 332, 0, 13, 0, 0, 0, 0, 0, 0, 50,
	0, 0, 0, 0, 0, 0, 0, 0, 5, 403, 0, 0, 262, 72, 415, 0,
	0, 0, 0, 0, 278, 0, 200, 277, 0, 412, 0, 0, 0, 0, 396, 0,
	193, 366, 347, 0, 0, 295, 0, 0, 71, 470, 0, 0, 0, 0, 0, 125,
	0, 0, 103, 34, 218, 0, 49, 382, 0, 164, 417, 175, 385, 407, 199, 463,
	0, 67, 128, 0, 276, 0, 0, 0, 0, 97, 0, 0, 0, 0, 265, 78,
	15, 0, 0, 68, 0, 401, 0, 0, 0, 0, 0, 260, 0, 0, 0, 0,
	44, 0, 0, 285, 46, 0, 296, 0, 102, 273, 0, 0, 0, 0, 0, 0,
	178, 289, 0, 166, 0, 313, 0, 0, 0, 0, 0, 0, 211, 0, 24, 0,
	0, 400, 0, 0, 0, 335, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	369, 310, 0, 0, 0, 0, 434, 0, 0, 0, 0, 0, 146, 0, 0, 0,
	0, 248, 0, 0, 114, 179, 0, 414, 0, 378, 0, 0, 0, 0, 0, 73,
	0, 250, 0, 0, 0, 0, 14, 57, 30, 215, 0, 0, 0, 0, 454, 0,
	0, 0, 0, 0, 43, 319, 0, 0, 0, 0, 0, 12, 89, 87, 240, 172,
	394, 274, 328, 0, 0, 425, 420, 0, 209, 0, 404, 0, 433, 0, 0, 0,
	0, 363, 0, 177, 371, 63, 0, 0, 0, 151, 0, 0, 207, 99, 0, 0,
	309, 171, 300, 264, 353, 258, 0, 0, 0, 0, 0, 0, 221, 85, 154, 0,
	0, 160, 279, 0, 357, 0, 302, 462, 0, 0, 0, 0, 0, 0, 149, 238,
	325, 0, 0, 337, 0, 223, 0, 0, 334, 36, 0, 0, 0, 132, 0, 0,
	0, 391, 0, 0, 0, 0, 0, 0, 0, 0, 94, 19, 0, 83, 37, 0,
	308, 41, 0, 0, 208, 0, 0, 0, 0, 0, 56, 251, 4, 0, 0, 32,
	351, 388, 0, 0, 173, 0, 159, 77, 410, 0, 0, 0, 0, 298, 81, 231,
	0, 356, 0, 270, 292, 288, 358, 0, 0, 0, 413, 0, 0, 0, 0, 0,
	157, 0, 18, 0, 123, 112, 0, 0, 441, 443, 0, 0, 0, 318, 267, 0,
	0, 0, 0, 0, 80, 0, 0, 338, 307, 0, 0, 188, 252, 303, 239, 0,
	0, 40, 117, 0, 311, 0, 275, 0, 408, 0, 17, 0, 0, 16, 148, 0,
	0, 399, 124, 0, 427, 0, 122, 0, 219, 440, 280, 236, 111, 185, 0, 0,
	0, 0, 0, 299, 0, 0, 0, 0, 406, 244, 0, 437, 0, 0, 224, 74,
	424, 0, 39, 27, 29, 448, 104, 0, 0, 243, 0, 0, 0, 0, 0, 167,
	322, 0, 121, 373, 155, 0, 0, 355, 435, 0, 76, 129, 422, 161, 0, 0,
	162, 284, 333, 0, 0, 0, 0, 0, 245, 376, 0, 0, 0, 0, 0, 432,
	0, 0, 0, 86, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 6, 232, 395, 301, 156, 315, 419, 0, 0, 0, 0, 0, 352,
	0, 0, 0, 226, 0, 0, 0, 0, 444, 0, 0, 0, 0, 0, 0, 3,
	0, 0, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, 339, 0, 0, 235,
	54, 201, 304, 0, 0, 436, 7, 0, 0, 0, 0, 0, 0, 0, 96, 0,
	152, 190, 362, 0, 377, 365, 20, 350, 95, 84, 0, 75, 0, 469, 165, 118,
	8, 336, 0, 0, 426, 0, 98, 0, 0, 0, 0, 0, 0, 283, 0, 281,
	10, 383, 130, 126, 402, 131, 361, 429, 392, 0, 386, 0, 0, 0, 35, 42,
	0, 0, 88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192,
	205, 375, 26, 0, 389, 144, 0, 150, 237, 0, 0, 0, 0, 113, 0, 0,
	0, 0, 0, 268, 0, 305, 421, 0, 0, 0, 0, 66, 92, 143, 116, 0,
	446, 294, 0, 0, 0, 53, 0, 0, 51, 101, 411, 93, 69, 380, 467, 0,
	0, 0, 0, 0, 0, 0, 0, 464, 0, 0, 0, 0, 0, 0, 0, 0,
};
const kh_n2sp_t n2s_tbl = { .n_buckets = 1024, .size = 471, .n_occupied = 471, .ed_flags = (uint8_t *)&n2s_tbl_ed_flags, .keys = (mrb_sym *)&n2s_tbl_keys, .vals = NULL };

PRESET_CONST mrb_value mrb_preset_irep_10_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_35 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_11_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_37 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_12_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_39 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_13_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_41 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_16_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_45 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_46 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_17_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_48 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_49 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_50 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_18_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_52 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_19_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_54 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_21_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_56 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_57 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_58 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_22_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_60 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_25_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_62 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_63 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_26_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_65 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_27_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_67 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_68 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_28_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_70 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_29_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_72 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_73 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_74 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_75 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_76 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_77 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_78 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_79 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_80 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_81 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_82 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_83 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_84 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_85 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_86 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_30_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_88 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_31_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_90 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_91 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_92 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_33_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_95 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_35_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_97 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_98 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_99 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_36_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_101 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_102 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_103 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_37_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_105 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_39_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_109 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_110 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_111 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_112 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_113 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_114 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_115 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_40_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_117 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_118 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_119 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_41_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_121 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_122 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_123 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_42_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_125 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_44_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_130 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_131 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_132 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_46_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_135 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_136 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_137 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_47_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_139 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_140 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_141 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_48_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_143 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_144 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_145 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_52_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_152 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_153 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_154 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_155 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_56_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_159 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_57_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_161 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_162 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_65_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_172 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_69_pool[] = {
	{ .value = { .i = 2147483647 }, .tt = MRB_TT_FIXNUM },
};
PRESET_CONST mrb_value mrb_preset_irep_101_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_216 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_103_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_218 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_104_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_220 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_221 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_222 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_223 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_105_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_224 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_109_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_228 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_141_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_249 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_250 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_145_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_257 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_151_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_286 }, .tt = MRB_TT_STRING },
};
PRESET_CONST mrb_value mrb_preset_irep_152_pool[] = {
	{ .value = { .p = (void *)&mrb_preset_object_288 }, .tt = MRB_TT_STRING },
};

PRESET_CONST mrb_sym mrb_preset_irep_0_syms[] = { 124, 250, };
PRESET_CONST mrb_sym mrb_preset_irep_1_syms[] = { 26, 28, };
PRESET_CONST mrb_sym mrb_preset_irep_2_syms[] = { 40, 41, };
PRESET_CONST mrb_sym mrb_preset_irep_3_syms[] = { 124, 250, };
PRESET_CONST mrb_sym mrb_preset_irep_4_syms[] = { 24, 23, };
PRESET_CONST mrb_sym mrb_preset_irep_5_syms[] = { 106, };
PRESET_CONST mrb_sym mrb_preset_irep_6_syms[] = { 203, };
PRESET_CONST mrb_sym mrb_preset_irep_7_syms[] = { 86, 151, 463, };
PRESET_CONST mrb_sym mrb_preset_irep_8_syms[] = { 94, 132, };
PRESET_CONST mrb_sym mrb_preset_irep_9_syms[] = { 117, 105, 132, 241, };
PRESET_CONST mrb_sym mrb_preset_irep_10_syms[] = { 78, 69, 245, 433, 10, 123, };
PRESET_CONST mrb_sym mrb_preset_irep_11_syms[] = { 78, 69, 142, 434, 10, 123, };
PRESET_CONST mrb_sym mrb_preset_irep_12_syms[] = { 78, 69, 245, 435, 10, 123, };
PRESET_CONST mrb_sym mrb_preset_irep_13_syms[] = { 94, 132, 3, 47, 314, 15, 313, 69, 244, };
PRESET_CONST mrb_sym mrb_preset_irep_14_syms[] = { 135, 149, 110, 108, 189, 127, };
PRESET_CONST mrb_sym mrb_preset_irep_15_syms[] = { 153, };
PRESET_CONST mrb_sym mrb_preset_irep_16_syms[] = { 127, 202, 108, 190, 25, 110, 192, };
PRESET_CONST mrb_sym mrb_preset_irep_17_syms[] = { 127, 202, 108, 190, 25, 110, 192, };
PRESET_CONST mrb_sym mrb_preset_irep_18_syms[] = { 78, 69, 245, 309, 10, 123, };
PRESET_CONST mrb_sym mrb_preset_irep_19_syms[] = { 261, 311, 129, 250, };
PRESET_CONST mrb_sym mrb_preset_irep_20_syms[] = { 149, };
PRESET_CONST mrb_sym mrb_preset_irep_21_syms[] = { 25, 122, 69, 234, 132, 10, 73, 120, 152, 110, 108, 149, 42, 305, 189, 158, };
PRESET_CONST mrb_sym mrb_preset_irep_22_syms[] = { 127, 65, 129, 250, 262, };
PRESET_CONST mrb_sym mrb_preset_irep_23_syms[] = { 149, 427, };
PRESET_CONST mrb_sym mrb_preset_irep_24_syms[] = { 427, };
PRESET_CONST mrb_sym mrb_preset_irep_25_syms[] = { 127, 202, 190, 25, 110, 192, };
PRESET_CONST mrb_sym mrb_preset_irep_26_syms[] = { 78, 69, 245, 122, 10, 9, 261, 307, 306, 123, };
PRESET_CONST mrb_sym mrb_preset_irep_27_syms[] = { 122, 10, 9, 261, 306, 25, 69, 234, 61, 132, 152, 110, 202, 108, 149, 42, 305, 120, 189, 158, };
PRESET_CONST mrb_sym mrb_preset_irep_28_syms[] = { 3, 47, 314, 69, 244, };
PRESET_CONST mrb_sym mrb_preset_irep_29_syms[] = { 10, 122, 202, 110, 108, 55, 120, };
PRESET_CONST mrb_sym mrb_preset_irep_30_syms[] = { 261, 304, 61, 149, 132, 122, 73, 110, 108, 202, 120, 127, 191, };
PRESET_CONST mrb_sym mrb_preset_irep_31_syms[] = { 86, 106, 69, 239, 71, 120, 61, 108, 127, 128, 202, };
PRESET_CONST mrb_sym mrb_preset_irep_32_syms[] = { 439, 61, 10, };
PRESET_CONST mrb_sym mrb_preset_irep_33_syms[] = { 65, 129, 250, };
PRESET_CONST mrb_sym mrb_preset_irep_34_syms[] = { 149, };
PRESET_CONST mrb_sym mrb_preset_irep_35_syms[] = { 78, 69, 245, 61, 9, 189, 127, 108, 192, 190, 191, 110, 87, 212, 213, 214, 215, 202, 106, 10, 42, 120, 123, };
PRESET_CONST mrb_sym mrb_preset_irep_36_syms[] = { 86, 106, 69, 239, 71, 126, 61, 108, 127, 128, 202, };
PRESET_CONST mrb_sym mrb_preset_irep_37_syms[] = { 123, };
PRESET_CONST mrb_sym mrb_preset_irep_38_syms[] = { 10, 152, 189, 108, 153, };
PRESET_CONST mrb_sym mrb_preset_irep_39_syms[] = { 127, 10, 106, 55, 120, 110, 131, 108, 122, 123, 158, 69, 242, 212, 213, 214, 189, 215, 153, 202, 191, 234, };
PRESET_CONST mrb_sym mrb_preset_irep_40_syms[] = { 10, 69, 234, 190, 127, 187, 122, 197, 109, 110, 202, 108, };
PRESET_CONST mrb_sym mrb_preset_irep_41_syms[] = { 10, 69, 234, 190, 127, 187, 122, 197, 109, 110, 202, 108, };
PRESET_CONST mrb_sym mrb_preset_irep_42_syms[] = { 94, 132, 69, 239, 294, };
PRESET_CONST mrb_sym mrb_preset_irep_43_syms[] = { 105, 10, };
PRESET_CONST mrb_sym mrb_preset_irep_44_syms[] = { 105, 61, 69, 234, 71, 190, };
PRESET_CONST mrb_sym mrb_preset_irep_45_syms[] = { 192, 190, };
PRESET_CONST mrb_sym mrb_preset_irep_46_syms[] = { 105, 61, 69, 234, 71, 192, };
PRESET_CONST mrb_sym mrb_preset_irep_47_syms[] = { 105, 61, 69, 234, 71, 191, };
PRESET_CONST mrb_sym mrb_preset_irep_48_syms[] = { 105, 61, 69, 234, 71, 189, };
PRESET_CONST mrb_sym mrb_preset_irep_49_syms[] = { 261, 250, 149, 110, 108, 189, 122, };
PRESET_CONST mrb_sym mrb_preset_irep_50_syms[] = { 261, 256, 149, 108, 189, 122, };
PRESET_CONST mrb_sym mrb_preset_irep_51_syms[] = { 261, 257, 127, 149, 110, 153, 108, 189, };
PRESET_CONST mrb_sym mrb_preset_irep_52_syms[] = { 127, 10, 108, 262, 158, };
PRESET_CONST mrb_sym mrb_preset_irep_53_syms[] = { 43, };
PRESET_CONST mrb_sym mrb_preset_irep_54_syms[] = { 167, 10, 127, 191, 110, 105, 61, 11, 108, 189, 202, };
PRESET_CONST mrb_sym mrb_preset_irep_55_syms[] = { 166, 10, 127, 110, 11, 108, 189, };
PRESET_CONST mrb_sym mrb_preset_irep_56_syms[] = { 259, 145, };
PRESET_CONST mrb_sym mrb_preset_irep_57_syms[] = { 87, 195, 69, 239, 189, 234, 154, 191, 153, 202, 149, 108, };
PRESET_CONST mrb_sym mrb_preset_irep_58_syms[] = { 127, 191, 263, 202, };
PRESET_CONST mrb_sym mrb_preset_irep_59_syms[] = { 189, 110, 108, 202, 187, 149, 105, 192, 153, 263, };
PRESET_CONST mrb_sym mrb_preset_irep_60_syms[] = { 166, 10, 127, 110, 74, 108, 189, };
PRESET_CONST mrb_sym mrb_preset_irep_61_syms[] = { 156, 120, 61, 149, };
PRESET_CONST mrb_sym mrb_preset_irep_62_syms[] = { 73, 264, };
PRESET_CONST mrb_sym mrb_preset_irep_63_syms[] = { 261, 269, 250, };
PRESET_CONST mrb_sym mrb_preset_irep_64_syms[] = { 161, 149, };
PRESET_CONST mrb_sym mrb_preset_irep_65_syms[] = { 127, 191, 69, 234, 102, 55, 110, 160, 119, 250, };
PRESET_CONST mrb_sym mrb_preset_irep_66_syms[] = { 13, };
PRESET_CONST mrb_sym mrb_preset_irep_67_syms[] = { 169, 149, };
PRESET_CONST mrb_sym mrb_preset_irep_68_syms[] = { 250, };
PRESET_CONST mrb_sym mrb_preset_irep_69_syms[] = { 79, 58, 205, 203, 152, 59, 108, };
PRESET_CONST mrb_sym mrb_preset_irep_70_syms[] = { 250, };
PRESET_CONST mrb_sym mrb_preset_irep_71_syms[] = { 149, };
PRESET_CONST mrb_sym mrb_preset_irep_72_syms[] = { 169, };
PRESET_CONST mrb_sym mrb_preset_irep_73_syms[] = { 250, };
PRESET_CONST mrb_sym mrb_preset_irep_74_syms[] = { 149, 161, 169, };
PRESET_CONST mrb_sym mrb_preset_irep_75_syms[] = { 250, };
PRESET_CONST mrb_sym mrb_preset_irep_76_syms[] = { 169, 10, };
PRESET_CONST mrb_sym mrb_preset_irep_77_syms[] = { 250, };
PRESET_CONST mrb_sym mrb_preset_irep_78_syms[] = { 149, 161, 169, };
PRESET_CONST mrb_sym mrb_preset_irep_79_syms[] = { 250, };
PRESET_CONST mrb_sym mrb_preset_irep_80_syms[] = { 169, 149, 191, 105, };
PRESET_CONST mrb_sym mrb_preset_irep_81_syms[] = { 250, };
PRESET_CONST mrb_sym mrb_preset_irep_82_syms[] = { 169, 149, 189, 105, };
PRESET_CONST mrb_sym mrb_preset_irep_83_syms[] = { 262, 265, };
PRESET_CONST mrb_sym mrb_preset_irep_84_syms[] = { 169, };
PRESET_CONST mrb_sym mrb_preset_irep_85_syms[] = { 261, 271, 250, };
PRESET_CONST mrb_sym mrb_preset_irep_86_syms[] = { 149, 169, 108, };
PRESET_CONST mrb_sym mrb_preset_irep_87_syms[] = { 250, };
PRESET_CONST mrb_sym mrb_preset_irep_88_syms[] = { 149, 169, };
PRESET_CONST mrb_sym mrb_preset_irep_89_syms[] = { 250, };
PRESET_CONST mrb_sym mrb_preset_irep_90_syms[] = { 161, 169, };
PRESET_CONST mrb_sym mrb_preset_irep_91_syms[] = { 261, 274, 250, };
PRESET_CONST mrb_sym mrb_preset_irep_92_syms[] = { 149, 161, 169, };
PRESET_CONST mrb_sym mrb_preset_irep_93_syms[] = { 250, };
PRESET_CONST mrb_sym mrb_preset_irep_94_syms[] = { 169, 55, 161, 149, };
PRESET_CONST mrb_sym mrb_preset_irep_95_syms[] = { 250, };
PRESET_CONST mrb_sym mrb_preset_irep_96_syms[] = { 149, };
PRESET_CONST mrb_sym mrb_preset_irep_97_syms[] = { 169, };
PRESET_CONST mrb_sym mrb_preset_irep_98_syms[] = { 252, };
PRESET_CONST mrb_sym mrb_preset_irep_99_syms[] = { 254, };
PRESET_CONST mrb_sym mrb_preset_irep_101_syms[] = { 94, 184, 69, 239, 154, 284, 173, 174, 171, 172, };
PRESET_CONST mrb_sym mrb_preset_irep_102_syms[] = { 110, 153, };
PRESET_CONST mrb_sym mrb_preset_irep_103_syms[] = { 259, 145, };
PRESET_CONST mrb_sym mrb_preset_irep_104_syms[] = { 127, 10, 108, 262, 158, };
PRESET_CONST mrb_sym mrb_preset_irep_105_syms[] = { 259, 108, };
PRESET_CONST mrb_sym mrb_preset_irep_106_syms[] = { 176, 9, 149, 175, };
PRESET_CONST mrb_sym mrb_preset_irep_107_syms[] = { 75, 184, 241, 127, 11, 250, };
PRESET_CONST mrb_sym mrb_preset_irep_108_syms[] = { 178, 110, 10, };
PRESET_CONST mrb_sym mrb_preset_irep_109_syms[] = { 94, 184, 69, 239, 284, };
PRESET_CONST mrb_sym mrb_preset_irep_110_syms[] = { 110, 153, };
PRESET_CONST mrb_sym mrb_preset_irep_111_syms[] = { 176, 149, 110, 153, };
PRESET_CONST mrb_sym mrb_preset_irep_112_syms[] = { 110, 153, };
PRESET_CONST mrb_sym mrb_preset_irep_113_syms[] = { 284, };
PRESET_CONST mrb_sym mrb_preset_irep_114_syms[] = { 110, 153, };
PRESET_CONST mrb_sym mrb_preset_irep_115_syms[] = { 261, 287, 250, 127, 10, };
PRESET_CONST mrb_sym mrb_preset_irep_116_syms[] = { 149, 161, };
PRESET_CONST mrb_sym mrb_preset_irep_117_syms[] = { 260, };
PRESET_CONST mrb_sym mrb_preset_irep_118_syms[] = { 261, 288, 250, 127, 10, };
PRESET_CONST mrb_sym mrb_preset_irep_119_syms[] = { 149, 161, };
PRESET_CONST mrb_sym mrb_preset_irep_120_syms[] = { 260, };
PRESET_CONST mrb_sym mrb_preset_irep_121_syms[] = { 261, 284, 179, 250, };
PRESET_CONST mrb_sym mrb_preset_irep_122_syms[] = { 149, };
PRESET_CONST mrb_sym mrb_preset_irep_123_syms[] = { 261, 250, 179, 183, 127, 149, 110, 108, 189, };
PRESET_CONST mrb_sym mrb_preset_irep_124_syms[] = { 261, 285, 179, 250, };
PRESET_CONST mrb_sym mrb_preset_irep_125_syms[] = { 149, 110, };
PRESET_CONST mrb_sym mrb_preset_irep_126_syms[] = { 75, 184, 241, 127, 11, 250, };
PRESET_CONST mrb_sym mrb_preset_irep_127_syms[] = { 178, 110, 74, };
PRESET_CONST mrb_sym mrb_preset_irep_128_syms[] = { 250, 123, };
PRESET_CONST mrb_sym mrb_preset_irep_129_syms[] = { 153, };
PRESET_CONST mrb_sym mrb_preset_irep_130_syms[] = { 261, 282, 250, };
PRESET_CONST mrb_sym mrb_preset_irep_131_syms[] = { 149, 153, };
PRESET_CONST mrb_sym mrb_preset_irep_132_syms[] = { 261, 281, 250, };
PRESET_CONST mrb_sym mrb_preset_irep_133_syms[] = { 149, 153, };
PRESET_CONST mrb_sym mrb_preset_irep_134_syms[] = { 261, 298, 131, 149, 202, 192, };
PRESET_CONST mrb_sym mrb_preset_irep_135_syms[] = { 191, };
PRESET_CONST mrb_sym mrb_preset_irep_136_syms[] = { 108, };
PRESET_CONST mrb_sym mrb_preset_irep_137_syms[] = { 189, };
PRESET_CONST mrb_sym mrb_preset_irep_138_syms[] = { 10, };
PRESET_CONST mrb_sym mrb_preset_irep_139_syms[] = { 261, 301, 149, 108, 189, };
PRESET_CONST mrb_sym mrb_preset_irep_140_syms[] = { 10, };
PRESET_CONST mrb_sym mrb_preset_irep_141_syms[] = { 10, 69, 234, 261, 303, 99, 87, 207, 130, 149, 108, 191, 190, 192, };
PRESET_CONST mrb_sym mrb_preset_irep_142_syms[] = { 206, 110, };
PRESET_CONST mrb_sym mrb_preset_irep_143_syms[] = { 261, 302, 131, 149, 108, 190, };
PRESET_CONST mrb_sym mrb_preset_irep_144_syms[] = { 157, 79, 59, 159, 215, 108, };
PRESET_CONST mrb_sym mrb_preset_irep_145_syms[] = { 261, 250, 157, 159, 87, 201, 215, 108, 149, 189, 106, 94, 302, 300, 69, 239, 105, 191, 127, 9, 10, };
PRESET_CONST mrb_sym mrb_preset_irep_146_syms[] = { 202, };
PRESET_CONST mrb_sym mrb_preset_irep_147_syms[] = { 189, 296, };
PRESET_CONST mrb_sym mrb_preset_irep_149_syms[] = { 261, 292, 149, 246, 255, };
PRESET_CONST mrb_sym mrb_preset_irep_150_syms[] = { 43, };
PRESET_CONST mrb_sym mrb_preset_irep_151_syms[] = { 69, 244, 15, };
PRESET_CONST mrb_sym mrb_preset_irep_152_syms[] = { 69, 244, 15, };
PRESET_CONST mrb_sym mrb_preset_irep_153_syms[] = { 294, 9, };

PRESET_CONST struct mrb_irep *const mrb_preset_irep_0_reps[] = { &mrb_preset_irep_1, };
PRESET_CONST struct mrb_irep *const mrb_preset_irep_3_reps[] = { &mrb_preset_irep_4, };
PRESET_CONST struct mrb_irep *const mrb_preset_irep_5_reps[] = { &mrb_preset_irep_6, };
PRESET_CONST struct mrb_irep *const mrb_preset_irep_6_reps[] = { &mrb_preset_irep_7, };
PRESET_CONST struct mrb_irep *const mrb_preset_irep_19_reps[] = { &mrb_preset_irep_20, };
PRESET_CONST struct mrb_irep *const mrb_preset_irep_22_reps[] = { &mrb_preset_irep_23, &mrb_preset_irep_24, };
PRESET_CONST struct mrb_irep *const mrb_preset_irep_33_reps[] = { &mrb_preset_irep_34, };
PRESET_CONST struct mrb_irep *const mrb_preset_irep_52_reps[] = { &mrb_preset_irep_53, };
PRESET_CONST struct mrb_irep *const mrb_preset_irep_63_reps[] = { &mrb_preset_irep_64, };
PRESET_CONST struct mrb_irep *const mrb_preset_irep_65_reps[] = { &mrb_preset_irep_66, &mrb_preset_irep_67, };
PRESET_CONST struct mrb_irep *const mrb_preset_irep_68_reps[] = { &mrb_preset_irep_69, };
PRESET_CONST struct mrb_irep *const mrb_preset_irep_70_reps[] = { &mrb_preset_irep_71, &mrb_preset_irep_72, };
PRESET_CONST struct mrb_irep *const mrb_preset_irep_73_reps[] = { &mrb_preset_irep_74, };
PRESET_CONST struct mrb_irep *const mrb_preset_irep_75_reps[] = { &mrb_preset_irep_76, };
PRESET_CONST struct mrb_irep *const mrb_preset_irep_77_reps[] = { &mrb_preset_irep_78, };
PRESET_CONST struct mrb_irep *const mrb_preset_irep_79_reps[] = { &mrb_preset_irep_80, };
PRESET_CONST struct mrb_irep *const mrb_preset_irep_81_reps[] = { &mrb_preset_irep_82, };
PRESET_CONST struct mrb_irep *const mrb_preset_irep_83_reps[] = { &mrb_preset_irep_84, };
PRESET_CONST struct mrb_irep *const mrb_preset_irep_85_reps[] = { &mrb_preset_irep_86, };
PRESET_CONST struct mrb_irep *const mrb_preset_irep_87_reps[] = { &mrb_preset_irep_88, };
PRESET_CONST struct mrb_irep *const mrb_preset_irep_89_reps[] = { &mrb_preset_irep_90, };
PRESET_CONST struct mrb_irep *const mrb_preset_irep_91_reps[] = { &mrb_preset_irep_92, };
PRESET_CONST struct mrb_irep *const mrb_preset_irep_93_reps[] = { &mrb_preset_irep_94, };
PRESET_CONST struct mrb_irep *const mrb_preset_irep_95_reps[] = { &mrb_preset_irep_96, &mrb_preset_irep_97, };
PRESET_CONST struct mrb_irep *const mrb_preset_irep_101_reps[] = { &mrb_preset_irep_102, };
PRESET_CONST struct mrb_irep *const mrb_preset_irep_104_reps[] = { &mrb_preset_irep_105, };
PRESET_CONST struct mrb_irep *const mrb_preset_irep_107_reps[] = { &mrb_preset_irep_108, };
PRESET_CONST struct mrb_irep *const mrb_preset_irep_109_reps[] = { &mrb_preset_irep_110, &mrb_preset_irep_111, &mrb_preset_irep_112, };
PRESET_CONST struct mrb_irep *const mrb_preset_irep_113_reps[] = { &mrb_preset_irep_114, };
PRESET_CONST struct mrb_irep *const mrb_preset_irep_115_reps[] = { &mrb_preset_irep_116, &mrb_preset_irep_117, };
PRESET_CONST struct mrb_irep *const mrb_preset_irep_118_reps[] = { &mrb_preset_irep_119, &mrb_preset_irep_120, };
PRESET_CONST struct mrb_irep *const mrb_preset_irep_121_reps[] = { &mrb_preset_irep_122, };
PRESET_CONST struct mrb_irep *const mrb_preset_irep_124_reps[] = { &mrb_preset_irep_125, };
PRESET_CONST struct mrb_irep *const mrb_preset_irep_126_reps[] = { &mrb_preset_irep_127, };
PRESET_CONST struct mrb_irep *const mrb_preset_irep_128_reps[] = { &mrb_preset_irep_129, };
PRESET_CONST struct mrb_irep *const mrb_preset_irep_130_reps[] = { &mrb_preset_irep_131, };
PRESET_CONST struct mrb_irep *const mrb_preset_irep_132_reps[] = { &mrb_preset_irep_133, };

PRESET_CONST struct mrb_locals mrb_preset_irep_0_lvs[] = {
	{ .name = (mrb_sym)253, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_1_lvs[] = {
	{ .name = (mrb_sym)316, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_2_lvs[] = {
	{ .name = (mrb_sym)315, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_3_lvs[] = {
	{ .name = (mrb_sym)253, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_4_lvs[] = {
	{ .name = (mrb_sym)316, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_7_lvs[] = {
	{ .name = (mrb_sym)253, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_8_lvs[] = {
	{ .name = (mrb_sym)320, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_9_lvs[] = {
	{ .name = (mrb_sym)363, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_10_lvs[] = {
	{ .name = (mrb_sym)0, .r = 0 },
	{ .name = (mrb_sym)348, .r = 2 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_11_lvs[] = {
	{ .name = (mrb_sym)0, .r = 0 },
	{ .name = (mrb_sym)348, .r = 2 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_12_lvs[] = {
	{ .name = (mrb_sym)0, .r = 0 },
	{ .name = (mrb_sym)348, .r = 2 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_13_lvs[] = {
	{ .name = (mrb_sym)371, .r = 1 },
	{ .name = (mrb_sym)317, .r = 2 },
	{ .name = (mrb_sym)372, .r = 3 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_14_lvs[] = {
	{ .name = (mrb_sym)317, .r = 1 },
	{ .name = (mrb_sym)135, .r = 2 },
	{ .name = (mrb_sym)357, .r = 3 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_15_lvs[] = {
	{ .name = (mrb_sym)462, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_16_lvs[] = {
	{ .name = (mrb_sym)0, .r = 0 },
	{ .name = (mrb_sym)349, .r = 2 },
	{ .name = (mrb_sym)449, .r = 3 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_17_lvs[] = {
	{ .name = (mrb_sym)0, .r = 0 },
	{ .name = (mrb_sym)349, .r = 2 },
	{ .name = (mrb_sym)449, .r = 3 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_18_lvs[] = {
	{ .name = (mrb_sym)253, .r = 1 },
	{ .name = (mrb_sym)317, .r = 2 },
	{ .name = (mrb_sym)363, .r = 3 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_19_lvs[] = {
	{ .name = (mrb_sym)317, .r = 1 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_20_lvs[] = {
	{ .name = (mrb_sym)323, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_21_lvs[] = {
	{ .name = (mrb_sym)253, .r = 1 },
	{ .name = (mrb_sym)317, .r = 2 },
	{ .name = (mrb_sym)336, .r = 3 },
	{ .name = (mrb_sym)123, .r = 4 },
	{ .name = (mrb_sym)255, .r = 5 },
	{ .name = (mrb_sym)356, .r = 6 },
	{ .name = (mrb_sym)362, .r = 7 },
	{ .name = (mrb_sym)354, .r = 8 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_22_lvs[] = {
	{ .name = (mrb_sym)317, .r = 1 },
	{ .name = (mrb_sym)319, .r = 2 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_23_lvs[] = {
	{ .name = (mrb_sym)321, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_24_lvs[] = {
	{ .name = (mrb_sym)321, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_25_lvs[] = {
	{ .name = (mrb_sym)0, .r = 0 },
	{ .name = (mrb_sym)349, .r = 2 },
	{ .name = (mrb_sym)449, .r = 3 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_26_lvs[] = {
	{ .name = (mrb_sym)253, .r = 1 },
	{ .name = (mrb_sym)317, .r = 2 },
	{ .name = (mrb_sym)363, .r = 3 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_27_lvs[] = {
	{ .name = (mrb_sym)253, .r = 1 },
	{ .name = (mrb_sym)317, .r = 2 },
	{ .name = (mrb_sym)336, .r = 3 },
	{ .name = (mrb_sym)123, .r = 4 },
	{ .name = (mrb_sym)361, .r = 5 },
	{ .name = (mrb_sym)354, .r = 6 },
	{ .name = (mrb_sym)255, .r = 7 },
	{ .name = (mrb_sym)362, .r = 8 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_28_lvs[] = {
	{ .name = (mrb_sym)364, .r = 1 },
	{ .name = (mrb_sym)317, .r = 2 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_29_lvs[] = {
	{ .name = (mrb_sym)358, .r = 1 },
	{ .name = (mrb_sym)316, .r = 2 },
	{ .name = (mrb_sym)359, .r = 3 },
	{ .name = (mrb_sym)0, .r = 0 },
	{ .name = (mrb_sym)348, .r = 5 },
	{ .name = (mrb_sym)323, .r = 6 },
	{ .name = (mrb_sym)329, .r = 7 },
	{ .name = (mrb_sym)360, .r = 8 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_30_lvs[] = {
	{ .name = (mrb_sym)353, .r = 1 },
	{ .name = (mrb_sym)317, .r = 2 },
	{ .name = (mrb_sym)354, .r = 3 },
	{ .name = (mrb_sym)355, .r = 4 },
	{ .name = (mrb_sym)356, .r = 5 },
	{ .name = (mrb_sym)357, .r = 6 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_31_lvs[] = {
	{ .name = (mrb_sym)451, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
	{ .name = (mrb_sym)324, .r = 3 },
	{ .name = (mrb_sym)316, .r = 4 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_32_lvs[] = {
	{ .name = (mrb_sym)363, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
	{ .name = (mrb_sym)450, .r = 3 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_33_lvs[] = {
	{ .name = (mrb_sym)317, .r = 1 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_34_lvs[] = {
	{ .name = (mrb_sym)323, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_35_lvs[] = {
	{ .name = (mrb_sym)452, .r = 1 },
	{ .name = (mrb_sym)453, .r = 2 },
	{ .name = (mrb_sym)0, .r = 0 },
	{ .name = (mrb_sym)318, .r = 4 },
	{ .name = (mrb_sym)363, .r = 5 },
	{ .name = (mrb_sym)454, .r = 6 },
	{ .name = (mrb_sym)455, .r = 7 },
	{ .name = (mrb_sym)456, .r = 8 },
	{ .name = (mrb_sym)457, .r = 9 },
	{ .name = (mrb_sym)458, .r = 10 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_36_lvs[] = {
	{ .name = (mrb_sym)451, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
	{ .name = (mrb_sym)324, .r = 3 },
	{ .name = (mrb_sym)316, .r = 4 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_37_lvs[] = {
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_38_lvs[] = {
	{ .name = (mrb_sym)318, .r = 1 },
	{ .name = (mrb_sym)363, .r = 2 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_39_lvs[] = {
	{ .name = (mrb_sym)253, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
	{ .name = (mrb_sym)365, .r = 3 },
	{ .name = (mrb_sym)357, .r = 4 },
	{ .name = (mrb_sym)366, .r = 5 },
	{ .name = (mrb_sym)367, .r = 6 },
	{ .name = (mrb_sym)368, .r = 7 },
	{ .name = (mrb_sym)349, .r = 8 },
	{ .name = (mrb_sym)369, .r = 9 },
	{ .name = (mrb_sym)370, .r = 10 },
	{ .name = (mrb_sym)319, .r = 11 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_40_lvs[] = {
	{ .name = (mrb_sym)318, .r = 1 },
	{ .name = (mrb_sym)459, .r = 2 },
	{ .name = (mrb_sym)0, .r = 0 },
	{ .name = (mrb_sym)460, .r = 4 },
	{ .name = (mrb_sym)461, .r = 5 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_41_lvs[] = {
	{ .name = (mrb_sym)318, .r = 1 },
	{ .name = (mrb_sym)459, .r = 2 },
	{ .name = (mrb_sym)0, .r = 0 },
	{ .name = (mrb_sym)460, .r = 4 },
	{ .name = (mrb_sym)461, .r = 5 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_42_lvs[] = {
	{ .name = (mrb_sym)371, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_43_lvs[] = {
	{ .name = (mrb_sym)322, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
	{ .name = (mrb_sym)332, .r = 3 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_44_lvs[] = {
	{ .name = (mrb_sym)322, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
	{ .name = (mrb_sym)332, .r = 3 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_45_lvs[] = {
	{ .name = (mrb_sym)279, .r = 1 },
	{ .name = (mrb_sym)278, .r = 2 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_46_lvs[] = {
	{ .name = (mrb_sym)322, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
	{ .name = (mrb_sym)332, .r = 3 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_47_lvs[] = {
	{ .name = (mrb_sym)322, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
	{ .name = (mrb_sym)332, .r = 3 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_48_lvs[] = {
	{ .name = (mrb_sym)322, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
	{ .name = (mrb_sym)332, .r = 3 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_49_lvs[] = {
	{ .name = (mrb_sym)317, .r = 1 },
	{ .name = (mrb_sym)318, .r = 2 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_50_lvs[] = {
	{ .name = (mrb_sym)317, .r = 1 },
	{ .name = (mrb_sym)318, .r = 2 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_51_lvs[] = {
	{ .name = (mrb_sym)317, .r = 1 },
	{ .name = (mrb_sym)318, .r = 2 },
	{ .name = (mrb_sym)319, .r = 3 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_52_lvs[] = {
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_53_lvs[] = {
	{ .name = (mrb_sym)321, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_54_lvs[] = {
	{ .name = (mrb_sym)322, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
	{ .name = (mrb_sym)319, .r = 3 },
	{ .name = (mrb_sym)324, .r = 4 },
	{ .name = (mrb_sym)323, .r = 5 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_55_lvs[] = {
	{ .name = (mrb_sym)322, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
	{ .name = (mrb_sym)319, .r = 3 },
	{ .name = (mrb_sym)323, .r = 4 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_56_lvs[] = {
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_57_lvs[] = {
	{ .name = (mrb_sym)127, .r = 1 },
	{ .name = (mrb_sym)320, .r = 2 },
	{ .name = (mrb_sym)317, .r = 3 },
	{ .name = (mrb_sym)318, .r = 4 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_58_lvs[] = {
	{ .name = (mrb_sym)317, .r = 1 },
	{ .name = (mrb_sym)127, .r = 2 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_59_lvs[] = {
	{ .name = (mrb_sym)327, .r = 1 },
	{ .name = (mrb_sym)328, .r = 2 },
	{ .name = (mrb_sym)317, .r = 3 },
	{ .name = (mrb_sym)323, .r = 4 },
	{ .name = (mrb_sym)329, .r = 5 },
	{ .name = (mrb_sym)330, .r = 6 },
	{ .name = (mrb_sym)331, .r = 7 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_60_lvs[] = {
	{ .name = (mrb_sym)322, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
	{ .name = (mrb_sym)319, .r = 3 },
	{ .name = (mrb_sym)323, .r = 4 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_61_lvs[] = {
	{ .name = (mrb_sym)325, .r = 1 },
	{ .name = (mrb_sym)317, .r = 2 },
	{ .name = (mrb_sym)323, .r = 3 },
	{ .name = (mrb_sym)326, .r = 4 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_62_lvs[] = {
	{ .name = (mrb_sym)317, .r = 1 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_63_lvs[] = {
	{ .name = (mrb_sym)317, .r = 1 },
	{ .name = (mrb_sym)334, .r = 2 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_64_lvs[] = {
	{ .name = (mrb_sym)333, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_65_lvs[] = {
	{ .name = (mrb_sym)253, .r = 1 },
	{ .name = (mrb_sym)317, .r = 2 },
	{ .name = (mrb_sym)338, .r = 3 },
	{ .name = (mrb_sym)339, .r = 4 },
	{ .name = (mrb_sym)255, .r = 5 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_66_lvs[] = {
	{ .name = (mrb_sym)321, .r = 1 },
	{ .name = (mrb_sym)340, .r = 2 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_67_lvs[] = {
	{ .name = (mrb_sym)333, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_68_lvs[] = {
	{ .name = (mrb_sym)0, .r = 0 },
	{ .name = (mrb_sym)343, .r = 2 },
	{ .name = (mrb_sym)323, .r = 3 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_69_lvs[] = {
	{ .name = (mrb_sym)344, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
	{ .name = (mrb_sym)324, .r = 3 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_70_lvs[] = {
	{ .name = (mrb_sym)317, .r = 1 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_71_lvs[] = {
	{ .name = (mrb_sym)333, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_72_lvs[] = {
	{ .name = (mrb_sym)333, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_73_lvs[] = {
	{ .name = (mrb_sym)317, .r = 1 },
	{ .name = (mrb_sym)341, .r = 2 },
	{ .name = (mrb_sym)342, .r = 3 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_74_lvs[] = {
	{ .name = (mrb_sym)333, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_75_lvs[] = {
	{ .name = (mrb_sym)320, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_76_lvs[] = {
	{ .name = (mrb_sym)333, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_77_lvs[] = {
	{ .name = (mrb_sym)317, .r = 1 },
	{ .name = (mrb_sym)334, .r = 2 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_78_lvs[] = {
	{ .name = (mrb_sym)333, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_79_lvs[] = {
	{ .name = (mrb_sym)317, .r = 1 },
	{ .name = (mrb_sym)339, .r = 2 },
	{ .name = (mrb_sym)255, .r = 3 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_80_lvs[] = {
	{ .name = (mrb_sym)333, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_81_lvs[] = {
	{ .name = (mrb_sym)317, .r = 1 },
	{ .name = (mrb_sym)339, .r = 2 },
	{ .name = (mrb_sym)255, .r = 3 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_82_lvs[] = {
	{ .name = (mrb_sym)333, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_83_lvs[] = {
	{ .name = (mrb_sym)317, .r = 1 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_84_lvs[] = {
	{ .name = (mrb_sym)333, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_85_lvs[] = {
	{ .name = (mrb_sym)317, .r = 1 },
	{ .name = (mrb_sym)323, .r = 2 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_86_lvs[] = {
	{ .name = (mrb_sym)333, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_87_lvs[] = {
	{ .name = (mrb_sym)335, .r = 1 },
	{ .name = (mrb_sym)317, .r = 2 },
	{ .name = (mrb_sym)326, .r = 3 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_88_lvs[] = {
	{ .name = (mrb_sym)333, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_89_lvs[] = {
	{ .name = (mrb_sym)0, .r = 0 },
	{ .name = (mrb_sym)334, .r = 2 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_90_lvs[] = {
	{ .name = (mrb_sym)333, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_91_lvs[] = {
	{ .name = (mrb_sym)317, .r = 1 },
	{ .name = (mrb_sym)334, .r = 2 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_92_lvs[] = {
	{ .name = (mrb_sym)333, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_93_lvs[] = {
	{ .name = (mrb_sym)336, .r = 1 },
	{ .name = (mrb_sym)317, .r = 2 },
	{ .name = (mrb_sym)334, .r = 3 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_94_lvs[] = {
	{ .name = (mrb_sym)333, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
	{ .name = (mrb_sym)337, .r = 3 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_95_lvs[] = {
	{ .name = (mrb_sym)317, .r = 1 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_96_lvs[] = {
	{ .name = (mrb_sym)333, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_97_lvs[] = {
	{ .name = (mrb_sym)333, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_98_lvs[] = {
	{ .name = (mrb_sym)138, .r = 1 },
	{ .name = (mrb_sym)251, .r = 2 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_99_lvs[] = {
	{ .name = (mrb_sym)138, .r = 1 },
	{ .name = (mrb_sym)251, .r = 2 },
	{ .name = (mrb_sym)253, .r = 3 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_101_lvs[] = {
	{ .name = (mrb_sym)79, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_102_lvs[] = {
	{ .name = (mrb_sym)345, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_103_lvs[] = {
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_104_lvs[] = {
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_105_lvs[] = {
	{ .name = (mrb_sym)345, .r = 1 },
	{ .name = (mrb_sym)346, .r = 2 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_106_lvs[] = {
	{ .name = (mrb_sym)325, .r = 1 },
	{ .name = (mrb_sym)317, .r = 2 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_107_lvs[] = {
	{ .name = (mrb_sym)79, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_108_lvs[] = {
	{ .name = (mrb_sym)345, .r = 1 },
	{ .name = (mrb_sym)346, .r = 2 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_109_lvs[] = {
	{ .name = (mrb_sym)322, .r = 1 },
	{ .name = (mrb_sym)317, .r = 2 },
	{ .name = (mrb_sym)343, .r = 3 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_110_lvs[] = {
	{ .name = (mrb_sym)345, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_111_lvs[] = {
	{ .name = (mrb_sym)345, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_112_lvs[] = {
	{ .name = (mrb_sym)345, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_113_lvs[] = {
	{ .name = (mrb_sym)343, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_114_lvs[] = {
	{ .name = (mrb_sym)345, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_115_lvs[] = {
	{ .name = (mrb_sym)317, .r = 1 },
	{ .name = (mrb_sym)179, .r = 2 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_116_lvs[] = {
	{ .name = (mrb_sym)345, .r = 1 },
	{ .name = (mrb_sym)346, .r = 2 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_117_lvs[] = {
	{ .name = (mrb_sym)345, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_118_lvs[] = {
	{ .name = (mrb_sym)317, .r = 1 },
	{ .name = (mrb_sym)179, .r = 2 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_119_lvs[] = {
	{ .name = (mrb_sym)345, .r = 1 },
	{ .name = (mrb_sym)346, .r = 2 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_120_lvs[] = {
	{ .name = (mrb_sym)345, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_121_lvs[] = {
	{ .name = (mrb_sym)317, .r = 1 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_122_lvs[] = {
	{ .name = (mrb_sym)345, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_123_lvs[] = {
	{ .name = (mrb_sym)317, .r = 1 },
	{ .name = (mrb_sym)179, .r = 2 },
	{ .name = (mrb_sym)347, .r = 3 },
	{ .name = (mrb_sym)319, .r = 4 },
	{ .name = (mrb_sym)323, .r = 5 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_124_lvs[] = {
	{ .name = (mrb_sym)317, .r = 1 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_125_lvs[] = {
	{ .name = (mrb_sym)345, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_126_lvs[] = {
	{ .name = (mrb_sym)79, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_127_lvs[] = {
	{ .name = (mrb_sym)345, .r = 1 },
	{ .name = (mrb_sym)346, .r = 2 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_128_lvs[] = {
	{ .name = (mrb_sym)0, .r = 0 },
	{ .name = (mrb_sym)343, .r = 2 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_129_lvs[] = {
	{ .name = (mrb_sym)345, .r = 1 },
	{ .name = (mrb_sym)346, .r = 2 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_130_lvs[] = {
	{ .name = (mrb_sym)317, .r = 1 },
	{ .name = (mrb_sym)343, .r = 2 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_131_lvs[] = {
	{ .name = (mrb_sym)345, .r = 1 },
	{ .name = (mrb_sym)346, .r = 2 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_132_lvs[] = {
	{ .name = (mrb_sym)317, .r = 1 },
	{ .name = (mrb_sym)343, .r = 2 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_133_lvs[] = {
	{ .name = (mrb_sym)345, .r = 1 },
	{ .name = (mrb_sym)346, .r = 2 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_134_lvs[] = {
	{ .name = (mrb_sym)350, .r = 1 },
	{ .name = (mrb_sym)317, .r = 2 },
	{ .name = (mrb_sym)323, .r = 3 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_135_lvs[] = {
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_136_lvs[] = {
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_137_lvs[] = {
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_138_lvs[] = {
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_139_lvs[] = {
	{ .name = (mrb_sym)317, .r = 1 },
	{ .name = (mrb_sym)323, .r = 2 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_140_lvs[] = {
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_141_lvs[] = {
	{ .name = (mrb_sym)350, .r = 1 },
	{ .name = (mrb_sym)303, .r = 2 },
	{ .name = (mrb_sym)317, .r = 3 },
	{ .name = (mrb_sym)323, .r = 4 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_142_lvs[] = {
	{ .name = (mrb_sym)322, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_143_lvs[] = {
	{ .name = (mrb_sym)350, .r = 1 },
	{ .name = (mrb_sym)317, .r = 2 },
	{ .name = (mrb_sym)323, .r = 3 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_144_lvs[] = {
	{ .name = (mrb_sym)0, .r = 0 },
	{ .name = (mrb_sym)343, .r = 2 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_145_lvs[] = {
	{ .name = (mrb_sym)317, .r = 1 },
	{ .name = (mrb_sym)333, .r = 2 },
	{ .name = (mrb_sym)159, .r = 3 },
	{ .name = (mrb_sym)351, .r = 4 },
	{ .name = (mrb_sym)323, .r = 5 },
	{ .name = (mrb_sym)352, .r = 6 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_146_lvs[] = {
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_147_lvs[] = {
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_148_lvs[] = {
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_149_lvs[] = {
	{ .name = (mrb_sym)317, .r = 1 },
	{ .name = (mrb_sym)344, .r = 2 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_150_lvs[] = {
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_151_lvs[] = {
	{ .name = (mrb_sym)349, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_152_lvs[] = {
	{ .name = (mrb_sym)348, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_153_lvs[] = {
	{ .name = (mrb_sym)340, .r = 1 },
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_154_lvs[] = {
	{ .name = (mrb_sym)0, .r = 0 },
};
PRESET_CONST struct mrb_locals mrb_preset_irep_155_lvs[] = {
	{ .name = (mrb_sym)0, .r = 0 },
};




PRESET_CONST mrb_irep mrb_preset_irep_0 = {
	.nlocals = 3,
	.nregs = 5,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[1184],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_0_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_0_reps,
	.lv = (struct mrb_locals *)&mrb_preset_irep_0_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 7, .plen = 0, .slen = 2, .rlen = 1, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_1 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[1252],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_1_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_1_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 8, .plen = 0, .slen = 2, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_2 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[1092],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_2_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_2_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 10, .plen = 0, .slen = 2, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_3 = {
	.nlocals = 3,
	.nregs = 5,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[1336],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_3_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_3_reps,
	.lv = (struct mrb_locals *)&mrb_preset_irep_3_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 7, .plen = 0, .slen = 2, .rlen = 1, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_4 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[1404],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_4_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_4_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 8, .plen = 0, .slen = 2, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_5 = {
	.nlocals = 1,
	.nregs = 3,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)gem_mrblib_irep_mruby_sprintf)[48],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_5_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_5_reps,
	.lv = NULL,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 5, .plen = 0, .slen = 1, .rlen = 1, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_6 = {
	.nlocals = 1,
	.nregs = 3,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)gem_mrblib_irep_mruby_sprintf)[100],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_6_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_6_reps,
	.lv = NULL,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 5, .plen = 0, .slen = 1, .rlen = 1, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_7 = {
	.nlocals = 3,
	.nregs = 7,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)gem_mrblib_irep_mruby_sprintf)[148],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_7_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_7_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 16, .plen = 0, .slen = 3, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_8 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)gem_mrblib_irep_mruby_string_ext)[628],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_8_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_8_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 10, .plen = 0, .slen = 2, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_9 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)gem_mrblib_irep_mruby_string_ext)[2012],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_9_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_9_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 19, .plen = 0, .slen = 4, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_10 = {
	.nlocals = 3,
	.nregs = 7,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)gem_mrblib_irep_mruby_string_ext)[1448],
	.pool = (mrb_value *)&mrb_preset_irep_10_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_10_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_10_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 20, .plen = 1, .slen = 6, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_11 = {
	.nlocals = 3,
	.nregs = 7,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)gem_mrblib_irep_mruby_string_ext)[1636],
	.pool = (mrb_value *)&mrb_preset_irep_11_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_11_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_11_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 20, .plen = 1, .slen = 6, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_12 = {
	.nlocals = 3,
	.nregs = 7,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)gem_mrblib_irep_mruby_string_ext)[1824],
	.pool = (mrb_value *)&mrb_preset_irep_12_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_12_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_12_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 20, .plen = 1, .slen = 6, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_13 = {
	.nlocals = 4,
	.nregs = 8,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[22968],
	.pool = (mrb_value *)&mrb_preset_irep_13_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_13_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_13_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 27, .plen = 1, .slen = 9, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_14 = {
	.nlocals = 4,
	.nregs = 8,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[21500],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_14_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_14_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 21, .plen = 0, .slen = 6, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_15 = {
	.nlocals = 3,
	.nregs = 9,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)gem_mrblib_irep_mruby_string_ext)[5556],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_15_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_15_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 9, .plen = 0, .slen = 1, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_16 = {
	.nlocals = 4,
	.nregs = 8,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)gem_mrblib_irep_mruby_string_ext)[772],
	.pool = (mrb_value *)&mrb_preset_irep_16_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_16_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_16_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 32, .plen = 2, .slen = 7, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_17 = {
	.nlocals = 4,
	.nregs = 8,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)gem_mrblib_irep_mruby_string_ext)[1176],
	.pool = (mrb_value *)&mrb_preset_irep_17_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_17_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_17_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 46, .plen = 3, .slen = 7, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_18 = {
	.nlocals = 4,
	.nregs = 8,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[21180],
	.pool = (mrb_value *)&mrb_preset_irep_18_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_18_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_18_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 23, .plen = 1, .slen = 6, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_19 = {
	.nlocals = 2,
	.nregs = 5,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)gem_mrblib_irep_mruby_string_ext)[5132],
	.pool = (mrb_value *)&mrb_preset_irep_19_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_19_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_19_reps,
	.lv = (struct mrb_locals *)&mrb_preset_irep_19_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 14, .plen = 1, .slen = 4, .rlen = 1, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_20 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)gem_mrblib_irep_mruby_string_ext)[5252],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_20_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_20_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 5, .plen = 0, .slen = 1, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_21 = {
	.nlocals = 9,
	.nregs = 16,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[20588],
	.pool = (mrb_value *)&mrb_preset_irep_21_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_21_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_21_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 97, .plen = 3, .slen = 16, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_22 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)gem_mrblib_irep_mruby_string_ext)[5304],
	.pool = (mrb_value *)&mrb_preset_irep_22_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_22_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_22_reps,
	.lv = (struct mrb_locals *)&mrb_preset_irep_22_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 20, .plen = 1, .slen = 5, .rlen = 2, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_23 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)gem_mrblib_irep_mruby_string_ext)[5452],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_23_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_23_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 6, .plen = 0, .slen = 2, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_24 = {
	.nlocals = 3,
	.nregs = 5,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)gem_mrblib_irep_mruby_string_ext)[5512],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_24_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_24_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 4, .plen = 0, .slen = 1, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_25 = {
	.nlocals = 4,
	.nregs = 8,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)gem_mrblib_irep_mruby_string_ext)[976],
	.pool = (mrb_value *)&mrb_preset_irep_25_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_25_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_25_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 32, .plen = 2, .slen = 6, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_26 = {
	.nlocals = 4,
	.nregs = 8,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[20140],
	.pool = (mrb_value *)&mrb_preset_irep_26_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_26_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_26_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 37, .plen = 1, .slen = 10, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_27 = {
	.nlocals = 9,
	.nregs = 16,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[19440],
	.pool = (mrb_value *)&mrb_preset_irep_27_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_27_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_27_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 123, .plen = 2, .slen = 20, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_28 = {
	.nlocals = 3,
	.nregs = 7,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[20424],
	.pool = (mrb_value *)&mrb_preset_irep_28_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_28_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_28_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 12, .plen = 1, .slen = 5, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_29 = {
	.nlocals = 9,
	.nregs = 15,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[18824],
	.pool = (mrb_value *)&mrb_preset_irep_29_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_29_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_29_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 123, .plen = 15, .slen = 7, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_30 = {
	.nlocals = 7,
	.nregs = 13,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[18440],
	.pool = (mrb_value *)&mrb_preset_irep_30_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_30_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_30_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 66, .plen = 1, .slen = 13, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_31 = {
	.nlocals = 5,
	.nregs = 12,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)gem_mrblib_irep_mruby_string_ext)[2248],
	.pool = (mrb_value *)&mrb_preset_irep_31_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_31_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_31_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 45, .plen = 3, .slen = 11, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_32 = {
	.nlocals = 4,
	.nregs = 7,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)gem_mrblib_irep_mruby_string_ext)[2152],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_32_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_32_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 13, .plen = 0, .slen = 3, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_33 = {
	.nlocals = 2,
	.nregs = 5,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)gem_mrblib_irep_mruby_string_ext)[4964],
	.pool = (mrb_value *)&mrb_preset_irep_33_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_33_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_33_reps,
	.lv = (struct mrb_locals *)&mrb_preset_irep_33_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 15, .plen = 1, .slen = 3, .rlen = 1, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_34 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)gem_mrblib_irep_mruby_string_ext)[5080],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_34_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_34_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 5, .plen = 0, .slen = 1, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_35 = {
	.nlocals = 11,
	.nregs = 16,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)gem_mrblib_irep_mruby_string_ext)[2880],
	.pool = (mrb_value *)&mrb_preset_irep_35_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_35_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_35_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 275, .plen = 3, .slen = 23, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_36 = {
	.nlocals = 5,
	.nregs = 12,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)gem_mrblib_irep_mruby_string_ext)[2564],
	.pool = (mrb_value *)&mrb_preset_irep_36_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_36_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_36_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 45, .plen = 3, .slen = 11, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_37 = {
	.nlocals = 2,
	.nregs = 5,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)gem_mrblib_irep_mruby_string_ext)[716],
	.pool = (mrb_value *)&mrb_preset_irep_37_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_37_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_37_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 5, .plen = 1, .slen = 1, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_38 = {
	.nlocals = 4,
	.nregs = 10,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)gem_mrblib_irep_mruby_string_ext)[4244],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_38_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_38_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 25, .plen = 0, .slen = 5, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_39 = {
	.nlocals = 12,
	.nregs = 19,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[21644],
	.pool = (mrb_value *)&mrb_preset_irep_39_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_39_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_39_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 217, .plen = 7, .slen = 22, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_40 = {
	.nlocals = 6,
	.nregs = 11,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)gem_mrblib_irep_mruby_string_ext)[4392],
	.pool = (mrb_value *)&mrb_preset_irep_40_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_40_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_40_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 40, .plen = 3, .slen = 12, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_41 = {
	.nlocals = 6,
	.nregs = 11,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)gem_mrblib_irep_mruby_string_ext)[4680],
	.pool = (mrb_value *)&mrb_preset_irep_41_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_41_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_41_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 39, .plen = 3, .slen = 12, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_42 = {
	.nlocals = 3,
	.nregs = 7,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[22816],
	.pool = (mrb_value *)&mrb_preset_irep_42_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_42_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_42_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 13, .plen = 1, .slen = 5, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_43 = {
	.nlocals = 4,
	.nregs = 7,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[6088],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_43_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_43_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 8, .plen = 0, .slen = 2, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_44 = {
	.nlocals = 4,
	.nregs = 9,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[5880],
	.pool = (mrb_value *)&mrb_preset_irep_44_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_44_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_44_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 25, .plen = 3, .slen = 6, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_45 = {
	.nlocals = 4,
	.nregs = 7,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[6572],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_45_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_45_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 9, .plen = 0, .slen = 2, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_46 = {
	.nlocals = 4,
	.nregs = 9,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[6364],
	.pool = (mrb_value *)&mrb_preset_irep_46_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_46_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_46_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 25, .plen = 3, .slen = 6, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_47 = {
	.nlocals = 4,
	.nregs = 9,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[6156],
	.pool = (mrb_value *)&mrb_preset_irep_47_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_47_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_47_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 25, .plen = 3, .slen = 6, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_48 = {
	.nlocals = 4,
	.nregs = 9,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[5672],
	.pool = (mrb_value *)&mrb_preset_irep_48_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_48_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_48_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 25, .plen = 3, .slen = 6, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_49 = {
	.nlocals = 3,
	.nregs = 7,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[2540],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_49_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_49_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 24, .plen = 0, .slen = 7, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_50 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[2704],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_50_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_50_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 22, .plen = 0, .slen = 6, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_51 = {
	.nlocals = 4,
	.nregs = 9,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[2864],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_51_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_51_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 30, .plen = 0, .slen = 8, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_52 = {
	.nlocals = 2,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[3460],
	.pool = (mrb_value *)&mrb_preset_irep_52_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_52_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_52_reps,
	.lv = (struct mrb_locals *)&mrb_preset_irep_52_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 18, .plen = 4, .slen = 5, .rlen = 1, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_53 = {
	.nlocals = 3,
	.nregs = 5,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[3604],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_53_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_53_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 4, .plen = 0, .slen = 1, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_54 = {
	.nlocals = 6,
	.nregs = 10,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[4228],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_54_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_54_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 72, .plen = 0, .slen = 11, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_55 = {
	.nlocals = 5,
	.nregs = 9,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[3772],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_55_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_55_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 40, .plen = 0, .slen = 7, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_56 = {
	.nlocals = 2,
	.nregs = 4,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[3652],
	.pool = (mrb_value *)&mrb_preset_irep_56_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_56_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_56_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 15, .plen = 1, .slen = 2, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_57 = {
	.nlocals = 5,
	.nregs = 10,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[3060],
	.pool = (mrb_value *)&mrb_preset_irep_57_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_57_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_57_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 56, .plen = 2, .slen = 12, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_58 = {
	.nlocals = 3,
	.nregs = 8,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[5364],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_58_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_58_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 15, .plen = 0, .slen = 4, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_59 = {
	.nlocals = 8,
	.nregs = 13,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[4872],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_59_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_59_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 102, .plen = 0, .slen = 10, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_60 = {
	.nlocals = 5,
	.nregs = 9,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[3996],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_60_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_60_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 41, .plen = 0, .slen = 7, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_61 = {
	.nlocals = 5,
	.nregs = 8,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[4604],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_61_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_61_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 20, .plen = 0, .slen = 4, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_62 = {
	.nlocals = 2,
	.nregs = 4,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[5476],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_62_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_62_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 6, .plen = 0, .slen = 2, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_63 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[7640],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_63_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_63_reps,
	.lv = (struct mrb_locals *)&mrb_preset_irep_63_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 12, .plen = 0, .slen = 3, .rlen = 1, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_64 = {
	.nlocals = 3,
	.nregs = 7,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[7740],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_64_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_64_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 8, .plen = 0, .slen = 2, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_65 = {
	.nlocals = 6,
	.nregs = 10,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[8824],
	.pool = (mrb_value *)&mrb_preset_irep_65_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_65_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_65_reps,
	.lv = (struct mrb_locals *)&mrb_preset_irep_65_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 39, .plen = 1, .slen = 10, .rlen = 2, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_66 = {
	.nlocals = 4,
	.nregs = 8,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[9100],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_66_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_66_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 6, .plen = 0, .slen = 1, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_67 = {
	.nlocals = 3,
	.nregs = 7,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[9160],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_67_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_67_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 17, .plen = 0, .slen = 2, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_68 = {
	.nlocals = 4,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[10228],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_68_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_68_reps,
	.lv = (struct mrb_locals *)&mrb_preset_irep_68_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 7, .plen = 0, .slen = 1, .rlen = 1, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_69 = {
	.nlocals = 4,
	.nregs = 9,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[10288],
	.pool = (mrb_value *)&mrb_preset_irep_69_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_69_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_69_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 22, .plen = 1, .slen = 7, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_70 = {
	.nlocals = 2,
	.nregs = 4,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[7192],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_70_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_70_reps,
	.lv = (struct mrb_locals *)&mrb_preset_irep_70_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 11, .plen = 0, .slen = 1, .rlen = 2, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_71 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[7268],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_71_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_71_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 11, .plen = 0, .slen = 1, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_72 = {
	.nlocals = 3,
	.nregs = 5,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[7344],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_72_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_72_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 9, .plen = 0, .slen = 1, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_73 = {
	.nlocals = 4,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[9772],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_73_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_73_reps,
	.lv = (struct mrb_locals *)&mrb_preset_irep_73_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 10, .plen = 0, .slen = 1, .rlen = 1, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_74 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[9844],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_74_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_74_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 16, .plen = 0, .slen = 3, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_75 = {
	.nlocals = 3,
	.nregs = 5,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[8684],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_75_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_75_reps,
	.lv = (struct mrb_locals *)&mrb_preset_irep_75_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 6, .plen = 0, .slen = 1, .rlen = 1, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_76 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[8740],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_76_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_76_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 11, .plen = 0, .slen = 2, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_77 = {
	.nlocals = 3,
	.nregs = 5,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[9956],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_77_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_77_reps,
	.lv = (struct mrb_locals *)&mrb_preset_irep_77_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 6, .plen = 0, .slen = 1, .rlen = 1, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_78 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[10012],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_78_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_78_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 13, .plen = 0, .slen = 3, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_79 = {
	.nlocals = 4,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[9268],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_79_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_79_reps,
	.lv = (struct mrb_locals *)&mrb_preset_irep_79_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 7, .plen = 0, .slen = 1, .rlen = 1, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_80 = {
	.nlocals = 3,
	.nregs = 7,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[9328],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_80_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_80_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 35, .plen = 0, .slen = 4, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_81 = {
	.nlocals = 4,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[9520],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_81_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_81_reps,
	.lv = (struct mrb_locals *)&mrb_preset_irep_81_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 7, .plen = 0, .slen = 1, .rlen = 1, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_82 = {
	.nlocals = 3,
	.nregs = 7,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[9580],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_82_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_82_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 35, .plen = 0, .slen = 4, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_83 = {
	.nlocals = 2,
	.nregs = 4,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[10112],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_83_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_83_reps,
	.lv = (struct mrb_locals *)&mrb_preset_irep_83_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 7, .plen = 0, .slen = 2, .rlen = 1, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_84 = {
	.nlocals = 3,
	.nregs = 5,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[10176],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_84_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_84_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 4, .plen = 0, .slen = 1, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_85 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[7972],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_85_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_85_reps,
	.lv = (struct mrb_locals *)&mrb_preset_irep_85_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 13, .plen = 0, .slen = 3, .rlen = 1, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_86 = {
	.nlocals = 3,
	.nregs = 7,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[8084],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_86_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_86_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 10, .plen = 0, .slen = 3, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_87 = {
	.nlocals = 4,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[7808],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_87_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_87_reps,
	.lv = (struct mrb_locals *)&mrb_preset_irep_87_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 9, .plen = 0, .slen = 1, .rlen = 1, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_88 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[7876],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_88_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_88_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 14, .plen = 0, .slen = 2, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_89 = {
	.nlocals = 3,
	.nregs = 5,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[8168],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_89_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_89_reps,
	.lv = (struct mrb_locals *)&mrb_preset_irep_89_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 6, .plen = 0, .slen = 1, .rlen = 1, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_90 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[8224],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_90_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_90_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 6, .plen = 0, .slen = 2, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_91 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[8288],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_91_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_91_reps,
	.lv = (struct mrb_locals *)&mrb_preset_irep_91_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 12, .plen = 0, .slen = 3, .rlen = 1, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_92 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[8388],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_92_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_92_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 13, .plen = 0, .slen = 3, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_93 = {
	.nlocals = 4,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[8488],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_93_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_93_reps,
	.lv = (struct mrb_locals *)&mrb_preset_irep_93_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 6, .plen = 0, .slen = 1, .rlen = 1, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_94 = {
	.nlocals = 4,
	.nregs = 8,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[8544],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_94_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_94_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 21, .plen = 0, .slen = 4, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_95 = {
	.nlocals = 2,
	.nregs = 4,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[7416],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_95_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_95_reps,
	.lv = (struct mrb_locals *)&mrb_preset_irep_95_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 11, .plen = 0, .slen = 1, .rlen = 2, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_96 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[7492],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_96_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_96_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 11, .plen = 0, .slen = 1, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_97 = {
	.nlocals = 3,
	.nregs = 5,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[7568],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_97_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_97_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 9, .plen = 0, .slen = 1, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_98 = {
	.nlocals = 4,
	.nregs = 7,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[1776],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_98_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_98_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 12, .plen = 0, .slen = 1, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_99 = {
	.nlocals = 5,
	.nregs = 9,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[1944],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_99_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_99_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 15, .plen = 0, .slen = 1, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_100 = {
	.nlocals = 0,
	.nregs = 2,
	.flags = 0x1,
	.iseq = (mrb_code *)&call_iseq,
	.pool = NULL,
	.syms = NULL,
	.reps = NULL,
	.lv = NULL,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 1, .plen = 0, .slen = 0, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_101 = {
	.nlocals = 3,
	.nregs = 7,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[12328],
	.pool = (mrb_value *)&mrb_preset_irep_101_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_101_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_101_reps,
	.lv = (struct mrb_locals *)&mrb_preset_irep_101_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 33, .plen = 1, .slen = 10, .rlen = 1, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_102 = {
	.nlocals = 3,
	.nregs = 8,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[12632],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_102_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_102_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 9, .plen = 0, .slen = 2, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_103 = {
	.nlocals = 2,
	.nregs = 4,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[13432],
	.pool = (mrb_value *)&mrb_preset_irep_103_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_103_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_103_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 15, .plen = 1, .slen = 2, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_104 = {
	.nlocals = 2,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[13208],
	.pool = (mrb_value *)&mrb_preset_irep_104_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_104_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_104_reps,
	.lv = (struct mrb_locals *)&mrb_preset_irep_104_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 18, .plen = 4, .slen = 5, .rlen = 1, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_105 = {
	.nlocals = 4,
	.nregs = 7,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[13352],
	.pool = (mrb_value *)&mrb_preset_irep_105_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_105_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_105_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 9, .plen = 1, .slen = 2, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_106 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[11640],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_106_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_106_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 16, .plen = 0, .slen = 4, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_107 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[10956],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_107_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_107_reps,
	.lv = (struct mrb_locals *)&mrb_preset_irep_107_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 35, .plen = 0, .slen = 6, .rlen = 1, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_108 = {
	.nlocals = 4,
	.nregs = 8,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[11172],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_108_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_108_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 21, .plen = 0, .slen = 3, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_109 = {
	.nlocals = 4,
	.nregs = 8,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[12704],
	.pool = (mrb_value *)&mrb_preset_irep_109_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_109_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_109_reps,
	.lv = (struct mrb_locals *)&mrb_preset_irep_109_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 26, .plen = 1, .slen = 5, .rlen = 3, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_110 = {
	.nlocals = 3,
	.nregs = 8,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[12920],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_110_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_110_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 9, .plen = 0, .slen = 2, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_111 = {
	.nlocals = 3,
	.nregs = 9,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[12992],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_111_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_111_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 23, .plen = 0, .slen = 4, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_112 = {
	.nlocals = 3,
	.nregs = 8,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[13136],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_112_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_112_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 9, .plen = 0, .slen = 2, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_113 = {
	.nlocals = 3,
	.nregs = 5,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[14660],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_113_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_113_reps,
	.lv = (struct mrb_locals *)&mrb_preset_irep_113_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 6, .plen = 0, .slen = 1, .rlen = 1, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_114 = {
	.nlocals = 3,
	.nregs = 8,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[14720],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_114_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_114_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 9, .plen = 0, .slen = 2, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_115 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[13552],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_115_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_115_reps,
	.lv = (struct mrb_locals *)&mrb_preset_irep_115_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 23, .plen = 0, .slen = 5, .rlen = 2, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_116 = {
	.nlocals = 4,
	.nregs = 7,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[13708],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_116_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_116_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 13, .plen = 0, .slen = 2, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_117 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[13796],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_117_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_117_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 5, .plen = 0, .slen = 1, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_118 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[14040],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_118_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_118_reps,
	.lv = (struct mrb_locals *)&mrb_preset_irep_118_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 23, .plen = 0, .slen = 5, .rlen = 2, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_119 = {
	.nlocals = 4,
	.nregs = 7,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[14196],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_119_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_119_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 13, .plen = 0, .slen = 2, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_120 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[14284],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_120_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_120_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 5, .plen = 0, .slen = 1, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_121 = {
	.nlocals = 2,
	.nregs = 5,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[11988],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_121_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_121_reps,
	.lv = (struct mrb_locals *)&mrb_preset_irep_121_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 13, .plen = 0, .slen = 4, .rlen = 1, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_122 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[12100],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_122_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_122_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 5, .plen = 0, .slen = 1, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_123 = {
	.nlocals = 6,
	.nregs = 11,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[11760],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_123_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_123_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 36, .plen = 0, .slen = 9, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_124 = {
	.nlocals = 2,
	.nregs = 5,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[12152],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_124_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_124_reps,
	.lv = (struct mrb_locals *)&mrb_preset_irep_124_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 13, .plen = 0, .slen = 4, .rlen = 1, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_125 = {
	.nlocals = 3,
	.nregs = 7,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[12264],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_125_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_125_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 7, .plen = 0, .slen = 2, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_126 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[11296],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_126_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_126_reps,
	.lv = (struct mrb_locals *)&mrb_preset_irep_126_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 35, .plen = 0, .slen = 6, .rlen = 1, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_127 = {
	.nlocals = 4,
	.nregs = 8,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[11512],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_127_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_127_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 21, .plen = 0, .slen = 3, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_128 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[14528],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_128_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_128_reps,
	.lv = (struct mrb_locals *)&mrb_preset_irep_128_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 9, .plen = 0, .slen = 2, .rlen = 1, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_129 = {
	.nlocals = 4,
	.nregs = 9,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[14604],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_129_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_129_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 7, .plen = 0, .slen = 1, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_130 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[14336],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_130_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_130_reps,
	.lv = (struct mrb_locals *)&mrb_preset_irep_130_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 12, .plen = 0, .slen = 3, .rlen = 1, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_131 = {
	.nlocals = 4,
	.nregs = 9,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[14432],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_131_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_131_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 15, .plen = 0, .slen = 2, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_132 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[13848],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_132_syms,
	.reps = (struct mrb_irep **)&mrb_preset_irep_132_reps,
	.lv = (struct mrb_locals *)&mrb_preset_irep_132_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 12, .plen = 0, .slen = 3, .rlen = 1, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_133 = {
	.nlocals = 4,
	.nregs = 9,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[13944],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_133_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_133_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 15, .plen = 0, .slen = 2, .rlen = 0, .refcnt = 1
};
PRESET_CONST mrb_irep mrb_preset_irep_134 = {
	.nlocals = 4,
	.nregs = 8,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[15948],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_134_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_134_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 24, .plen = 0, .slen = 6, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_135 = {
	.nlocals = 2,
	.nregs = 5,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)gem_mrblib_irep_mruby_numeric_ext)[416],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_135_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_135_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 5, .plen = 0, .slen = 1, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_136 = {
	.nlocals = 2,
	.nregs = 5,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[16108],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_136_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_136_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 4, .plen = 0, .slen = 1, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_137 = {
	.nlocals = 2,
	.nregs = 5,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)gem_mrblib_irep_mruby_numeric_ext)[464],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_137_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_137_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 5, .plen = 0, .slen = 1, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_138 = {
	.nlocals = 2,
	.nregs = 5,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)gem_mrblib_irep_mruby_numeric_ext)[352],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_138_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_138_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 9, .plen = 0, .slen = 1, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_139 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[16152],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_139_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_139_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 21, .plen = 0, .slen = 5, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_140 = {
	.nlocals = 2,
	.nregs = 5,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)gem_mrblib_irep_mruby_numeric_ext)[304],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_140_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_140_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 5, .plen = 0, .slen = 1, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_141 = {
	.nlocals = 5,
	.nregs = 10,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[16452],
	.pool = (mrb_value *)&mrb_preset_irep_141_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_141_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_141_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 82, .plen = 2, .slen = 14, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_142 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)gem_mrblib_irep_mruby_numeric_ext)[240],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_142_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_142_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 7, .plen = 0, .slen = 2, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_143 = {
	.nlocals = 4,
	.nregs = 8,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[16292],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_143_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_143_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 24, .plen = 0, .slen = 6, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_144 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[17928],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_144_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_144_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 16, .plen = 0, .slen = 6, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_145 = {
	.nlocals = 7,
	.nregs = 11,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[17256],
	.pool = (mrb_value *)&mrb_preset_irep_145_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_145_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_145_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 117, .plen = 1, .slen = 21, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_146 = {
	.nlocals = 2,
	.nregs = 5,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[15656],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_146_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_146_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 5, .plen = 0, .slen = 1, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_147 = {
	.nlocals = 2,
	.nregs = 5,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[15704],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_147_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_147_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 10, .plen = 0, .slen = 2, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_148 = {
	.nlocals = 2,
	.nregs = 3,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[15620],
	.pool = NULL,
	.syms = NULL,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_148_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 3, .plen = 0, .slen = 0, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_149 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[15100],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_149_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_149_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 26, .plen = 0, .slen = 5, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_150 = {
	.nlocals = 2,
	.nregs = 4,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[15332],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_150_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_150_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 4, .plen = 0, .slen = 1, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_151 = {
	.nlocals = 3,
	.nregs = 7,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[15380],
	.pool = (mrb_value *)&mrb_preset_irep_151_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_151_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_151_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 7, .plen = 1, .slen = 3, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_152 = {
	.nlocals = 3,
	.nregs = 7,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[14984],
	.pool = (mrb_value *)&mrb_preset_irep_152_pool,
	.syms = (mrb_sym *)&mrb_preset_irep_152_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_152_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 7, .plen = 1, .slen = 3, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_153 = {
	.nlocals = 3,
	.nregs = 6,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[15276],
	.pool = NULL,
	.syms = (mrb_sym *)&mrb_preset_irep_153_syms,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_153_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 6, .plen = 0, .slen = 2, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_154 = {
	.nlocals = 2,
	.nregs = 3,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[17116],
	.pool = NULL,
	.syms = NULL,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_154_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 3, .plen = 0, .slen = 0, .rlen = 0, .refcnt = 2
};
PRESET_CONST mrb_irep mrb_preset_irep_155 = {
	.nlocals = 2,
	.nregs = 3,
	.flags = 0x1,
	.iseq = (mrb_code *)&((uint8_t *)mrblib_irep)[17152],
	.pool = NULL,
	.syms = NULL,
	.reps = NULL,
	.lv = (struct mrb_locals *)&mrb_preset_irep_155_lvs,
	.own_filename = (mrb_bool)0,
	.filename = NULL,
	.lines = NULL,
	.debug_info = NULL,
	.ilen = 3, .plen = 0, .slen = 0, .rlen = 0, .refcnt = 2
};

PRESET_CONST mrb_value mrb_preset_env_stacks_24[] = {
	{ .value = { .sym = (mrb_sym)252 }, .tt = MRB_TT_SYMBOL },
};
PRESET_CONST mrb_value mrb_preset_env_stacks_189[] = {
	{ .value = { .sym = (mrb_sym)252 }, .tt = MRB_TT_SYMBOL },
};
PRESET_CONST mrb_value mrb_preset_env_stacks_192[] = {
	{ .value = { .sym = (mrb_sym)254 }, .tt = MRB_TT_SYMBOL },
};
PRESET_CONST mrb_value mrb_preset_env_stacks_201[] = {
	{ .value = { .sym = (mrb_sym)374 }, .tt = MRB_TT_SYMBOL },
};
PRESET_CONST mrb_value mrb_preset_env_stacks_203[] = {
	{ .value = { .sym = (mrb_sym)374 }, .tt = MRB_TT_SYMBOL },
};

PRESET_DATA uint8_t mrb_preset_iv_tbl_0_ed_flags[] = {
	0x2a, 0x8a, 0x02, 0x08, 0x20, 0x82, 0x02, 0x28, 0xaa, 0xaa, 0x28, 0xaa, 0xa2, 0xaa, 0xaa, 0xaa,
	0x88, 0x0a, 0xa0, 0xa0, 0x08, 0x2a, 0xa8, 0x2a, 0x82, 0x2a, 0x80, 0x82, 0x00, 0x28, 0x28, 0x02,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_0_keys[] = {
	0, 0, 0, 243, 0, 0, 242, 0, 0, 241, 2, 136, 240, 0, 216, 3,
	143, 5, 0, 246, 0, 4, 142, 0, 0, 244, 7, 141, 245, 0, 0, 6,
	0, 0, 0, 0, 0, 0, 0, 0, 170, 0, 0, 211, 0, 0, 0, 0,
	0, 212, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	207, 0, 231, 0, 0, 0, 376, 230, 229, 62, 0, 0, 63, 228, 0, 0,
	64, 0, 226, 57, 0, 0, 0, 227, 106, 0, 0, 0, 0, 0, 0, 201,
	0, 465, 237, 0, 0, 0, 0, 102, 239, 101, 236, 0, 0, 100, 151, 0,
	238, 145, 232, 185, 144, 0, 0, 233, 234, 0, 0, 147, 0, 235, 471, 195,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_0_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_1 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_14 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_19 }, .tt = MRB_TT_CLASS },
	{ .value = { .p = (void *)&mrb_preset_object_12 }, .tt = MRB_TT_CLASS },
	{ .value = { .p = (void *)&mrb_preset_object_18 }, .tt = MRB_TT_CLASS },
	{ .value = { .p = (void *)&mrb_preset_object_22 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_193 }, .tt = MRB_TT_MODULE },
	{ .value = { .p = (void *)&mrb_preset_object_0 }, .tt = MRB_TT_CLASS },
	{ .value = { .p = (void *)&mrb_preset_object_196 }, .tt = MRB_TT_CLASS },
	{ .value = { .p = (void *)&mrb_preset_object_3 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_198 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_6 }, .tt = MRB_TT_CLASS },
	{ .value = { .p = (void *)&mrb_preset_object_204 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_206 }, .tt = MRB_TT_CLASS },
	{ .value = { .p = (void *)&mrb_preset_object_208 }, .tt = MRB_TT_CLASS },
	{ .value = { .p = (void *)&mrb_preset_object_15 }, .tt = MRB_TT_CLASS },
	{ .value = { .p = (void *)&mrb_preset_object_211 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)3 }, .tt = MRB_TT_SYMBOL },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_213 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_240 }, .tt = MRB_TT_MODULE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_253 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_259 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_268 }, .tt = MRB_TT_STRING },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_269 }, .tt = MRB_TT_MODULE },
	{ .value = { .i = 10401 }, .tt = MRB_TT_FIXNUM },
	{ .value = { .p = (void *)&mrb_preset_object_275 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_276 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_278 }, .tt = MRB_TT_CLASS },
	{ .value = { .p = (void *)&mrb_preset_object_275 }, .tt = MRB_TT_STRING },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_280 }, .tt = MRB_TT_MODULE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_290 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_291 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_293 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_30 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_294 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_301 }, .tt = MRB_TT_CLASS },
	{ .value = { .p = (void *)&mrb_preset_object_303 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_307 }, .tt = MRB_TT_CLASS },
	{ .value = { .p = (void *)&mrb_preset_object_309 }, .tt = MRB_TT_CLASS },
	{ .value = { .p = (void *)&mrb_preset_object_169 }, .tt = MRB_TT_MODULE },
	{ .value = { .p = (void *)&mrb_preset_object_306 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_127 }, .tt = MRB_TT_MODULE },
	{ .value = { .p = (void *)&mrb_preset_object_147 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_311 }, .tt = MRB_TT_CLASS },
	{ .value = { .p = (void *)&mrb_preset_object_313 }, .tt = MRB_TT_CLASS },
	{ .value = { .p = (void *)&mrb_preset_object_315 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_262 }, .tt = MRB_TT_CLASS },
	{ .value = { .p = (void *)&mrb_preset_object_316 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_318 }, .tt = MRB_TT_STRING },
	{ .value = { .p = (void *)&mrb_preset_object_319 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_321 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_323 }, .tt = MRB_TT_CLASS },
	{ .value = { .p = (void *)&mrb_preset_object_325 }, .tt = MRB_TT_CLASS },
	{ .value = { .p = (void *)&mrb_preset_object_297 }, .tt = MRB_TT_CLASS },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_0 = { .n_buckets = 128, .size = 54, .n_occupied = 54, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_0_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_0_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_0_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_1_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_1_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_1_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)243 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_1 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_1_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_1_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_1_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_2_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_2_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_2_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_1 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_2 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_2_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_2_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_2_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_3_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_3_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_3_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)5 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_3 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_3_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_3_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_3_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_4_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_4_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_4_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_3 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_4 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_4_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_4_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_4_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_5_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_5_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_5_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_6 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_5 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_5_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_5_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_5_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_6_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_6_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_6_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)4 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_6 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_6_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_6_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_6_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_7_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_7_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_7_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_0 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_7 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_7_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_7_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_7_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_8_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_8_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_8_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_12 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_8 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_8_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_8_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_8_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_9_ed_flags[] = {
	0x8a, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_9_keys[] = {
	0, 0, 2, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_9_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_12 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)2 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_9 = { .n_buckets = 8, .size = 2, .n_occupied = 2, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_9_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_9_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_9_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_10_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_10_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_10_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_14 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_10 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_10_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_10_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_10_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_11_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_11_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_11_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)242 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_11 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_11_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_11_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_11_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_12_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_12_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_12_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)141 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_12 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_12_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_12_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_12_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_13_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_13_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_13_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_15 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_13 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_13_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_13_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_13_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_14_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_14_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_14_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_18 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_14 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_14_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_14_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_14_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_15_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_15_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_15_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)136 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_15 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_15_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_15_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_15_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_16_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_16_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_16_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)241 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_16 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_16_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_16_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_16_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_17_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_17_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_17_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_19 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_17 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_17_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_17_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_17_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_18_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_18_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_18_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_22 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_18 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_18_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_18_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_18_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_19_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_19_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_19_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)240 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_19 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_19_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_19_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_19_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_20_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_20_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_20_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_20 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_20_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_20_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_20_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_21_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_21_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_21_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_25 }, .tt = MRB_TT_OBJECT },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_21 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_21_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_21_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_21_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_22_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_22_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_22_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_26 }, .tt = MRB_TT_SCLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_22 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_22_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_22_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_22_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_23_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_23_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_23_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)106 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_23 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_23_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_23_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_23_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_24_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_24_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_24_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_30 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_24 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_24_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_24_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_24_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_25_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_25_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_25_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)100 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_25 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_25_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_25_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_25_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_26_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_26_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_26_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)151 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_26 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_26_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_26_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_26_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_27_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_27_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_27_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_147 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_27 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_27_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_27_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_27_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_28_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_28_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_28_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)101 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_28 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_28_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_28_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_28_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_29_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_29_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_29_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)216 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_29 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_29_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_29_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_29_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_30_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_30_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_30_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_193 }, .tt = MRB_TT_MODULE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_30 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_30_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_30_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_30_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_31_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_31_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_31_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_194 }, .tt = MRB_TT_SCLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_31 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_31_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_31_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_31_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_32_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_32_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_32_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)143 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_32 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_32_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_32_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_32_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_33_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_33_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_33_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_196 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_33 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_33_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_33_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_33_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_34_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_34_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_34_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)246 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_34 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_34_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_34_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_34_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_35_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_35_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_35_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_198 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_35 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_35_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_35_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_35_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_36_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_36_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_36_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)142 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_36 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_36_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_36_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_36_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_37_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_37_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_37_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_204 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_37 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_37_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_37_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_37_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_38_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_38_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_38_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)244 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_38 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_38_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_38_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_38_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_39_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_39_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_39_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_206 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_39 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_39_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_39_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_39_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_40_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_40_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_40_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)7 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_40 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_40_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_40_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_40_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_41_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_41_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_41_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_208 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_41 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_41_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_41_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_41_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_42_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_42_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_42_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)245 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_42 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_42_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_42_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_42_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_43_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_43_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_43_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_211 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_43 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_43_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_43_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_43_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_44_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_44_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_44_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)170 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_44 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_44_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_44_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_44_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_45_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_45_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_45_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_213 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_45 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_45_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_45_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_45_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_46_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_46_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_46_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)211 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_46 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_46_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_46_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_46_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_47_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_47_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_47_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)212 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_47 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_47_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_47_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_47_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_48_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_48_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_48_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_253 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_48 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_48_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_48_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_48_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_49_ed_flags[] = {
	0xa2, 0x0a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_49_keys[] = {
	0, 209, 0, 0, 0, 0, 210, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_49_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .f = INFINITY }, .tt = MRB_TT_FLOAT },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .f = NAN }, .tt = MRB_TT_FLOAT },
	{ .value = { .sym = (mrb_sym)207 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_49 = { .n_buckets = 8, .size = 3, .n_occupied = 3, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_49_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_49_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_49_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_50_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_50_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_50_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_259 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_50 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_50_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_50_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_50_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_51_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_51_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_51_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_262 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_51 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_51_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_51_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_51_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_52_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_52_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_52_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)185 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_52 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_52_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_52_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_52_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_53_ed_flags[] = {
	0x22, 0x08,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_53_keys[] = {
	0, 379, 0, 377, 378, 0, 380, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_53_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .f = 2.71828 }, .tt = MRB_TT_FLOAT },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_270 }, .tt = MRB_TT_CLASS },
	{ .value = { .f = 3.14159 }, .tt = MRB_TT_FLOAT },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .f = 1E-12 }, .tt = MRB_TT_FLOAT },
	{ .value = { .sym = (mrb_sym)376 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_53 = { .n_buckets = 8, .size = 5, .n_occupied = 5, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_53_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_53_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_53_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_54_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_54_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_54_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_271 }, .tt = MRB_TT_STRING },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_54 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_54_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_54_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_54_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_55_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_55_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_55_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_270 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_55 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_55_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_55_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_55_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_56_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_56_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_56_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_269 }, .tt = MRB_TT_MODULE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_56 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_56_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_56_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_56_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_57_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_57_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_57_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_273 }, .tt = MRB_TT_SCLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_57 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_57_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_57_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_57_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_58_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_58_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_58_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)62 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_58 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_58_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_58_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_58_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_59_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_59_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_59_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_276 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_59 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_59_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_59_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_59_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_60_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_60_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_60_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)63 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_60 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_60_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_60_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_60_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_61_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_61_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_61_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_278 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_61 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_61_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_61_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_61_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_62_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_62_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_62_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)64 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_62 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_62_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_62_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_62_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_63_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_63_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_63_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_280 }, .tt = MRB_TT_MODULE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_63 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_63_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_63_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_63_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_64_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_64_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_64_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_281 }, .tt = MRB_TT_SCLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_64 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_64_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_64_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_64_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_65_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_65_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_65_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)57 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_65 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_65_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_65_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_65_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_66_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_66_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_66_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_291 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_66 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_66_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_66_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_66_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_67_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_67_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_67_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)201 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_67 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_67_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_67_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_67_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_68_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_68_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_68_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_294 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_68 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_68_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_68_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_68_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_69_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_69_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_69_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_297 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_69 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_69_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_69_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_69_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_70_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_70_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_70_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)195 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_70 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_70_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_70_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_70_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_71_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_71_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_71_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)465 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_71 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_71_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_71_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_71_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_72_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_72_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_72_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_301 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_72 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_72_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_72_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_72_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_73_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_73_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_73_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)237 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_73 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_73_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_73_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_73_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_74_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_74_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_74_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_303 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_74 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_74_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_74_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_74_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_75_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_75_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_75_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_306 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_75 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_75_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_75_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_75_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_76_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_76_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_76_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)236 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_76 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_76_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_76_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_76_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_77_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_77_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_77_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)102 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_77 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_77_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_77_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_77_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_78_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_78_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_78_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_307 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_78 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_78_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_78_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_78_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_79_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_79_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_79_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)239 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_79 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_79_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_79_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_79_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_80_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_80_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_80_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_309 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_80 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_80_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_80_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_80_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_81_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_81_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_81_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)238 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_81 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_81_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_81_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_81_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_82_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_82_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_82_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_311 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_82 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_82_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_82_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_82_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_83_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_83_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_83_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)145 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_83 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_83_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_83_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_83_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_84_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_84_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_84_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_313 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_84 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_84_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_84_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_84_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_85_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_85_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_85_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)144 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_85 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_85_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_85_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_85_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_86_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_86_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_86_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_316 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_86 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_86_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_86_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_86_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_87_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_87_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_87_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)234 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_87 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_87_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_87_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_87_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_88_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_88_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_88_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_319 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_88 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_88_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_88_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_88_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_89_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_89_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_89_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)147 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_89 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_89_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_89_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_89_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_90_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_90_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_90_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_321 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_90 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_90_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_90_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_90_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_91_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_91_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_91_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)235 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_91 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_91_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_91_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_91_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_92_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_92_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_92_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_323 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_92 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_92_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_92_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_92_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_93_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_93_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 6,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_93_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .sym = (mrb_sym)471 }, .tt = MRB_TT_SYMBOL },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_93 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_93_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_93_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_93_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_94_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_94_keys[] = {
	0, 0, 0, 0, 0, 1, 0, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_94_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_325 }, .tt = MRB_TT_CLASS },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_94 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_94_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_94_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_94_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_95_ed_flags[] = {
	0xaa, 0x8a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_95_keys[] = {
	0, 0, 0, 0, 0, 0, 146, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_95_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_329 }, .tt = MRB_TT_STRING },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_95 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_95_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_95_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_95_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_96_ed_flags[] = {
	0xaa, 0x8a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_96_keys[] = {
	0, 0, 0, 0, 0, 0, 146, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_96_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_331 }, .tt = MRB_TT_STRING },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_96 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_96_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_96_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_96_vals };

PRESET_DATA uint8_t mrb_preset_iv_tbl_97_ed_flags[] = {
	0xaa, 0x8a,
};
PRESET_DATA mrb_sym mrb_preset_iv_tbl_97_keys[] = {
	0, 0, 0, 0, 0, 0, 146, 0,
};
PRESET_DATA mrb_value mrb_preset_iv_tbl_97_vals[] = {
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .p = (void *)&mrb_preset_object_333 }, .tt = MRB_TT_STRING },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};
PRESET_DATA kh_iv_t mrb_preset_iv_tbl_97 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_iv_tbl_97_ed_flags, .keys = (mrb_sym *)&mrb_preset_iv_tbl_97_keys, .vals = (mrb_value *)&mrb_preset_iv_tbl_97_vals };


PRESET_DATA uint8_t mrb_preset_kh_mt_0_ed_flags[] = {
	0xa8, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_0_keys[] = {
	15, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_0_vals[] = {
	{ .func_p = 1, { .func = (mrb_func_t)&mrb_class_new_class } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_0 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_0_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_0_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_0_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_1_ed_flags[] = {
	0x82, 0x28, 0x28, 0x82, 0x88, 0x0a, 0x20, 0x82, 0x02, 0x08, 0x00, 0x80, 0x00, 0x08, 0x20, 0x00,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_1_keys[] = {
	0, 20, 40, 0, 21, 0, 0, 41, 42, 0, 0, 22, 0, 43, 23, 0,
	249, 0, 45, 0, 0, 0, 247, 44, 47, 165, 0, 19, 0, 46, 18, 0,
	0, 30, 34, 54, 31, 0, 55, 35, 32, 52, 8, 28, 53, 33, 29, 0,
	248, 27, 39, 51, 26, 0, 50, 38, 37, 49, 0, 25, 48, 36, 24, 73,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_1_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_mod_cvar_set } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_mod_attr_reader } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_mod_extend_object } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_mod_attr_writer } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_mod_to_s } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_bob_init } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_mod_to_s } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_bob_init } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_7.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_mod_ancestors } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_8.proc } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_mod_alias } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_mod_const_defined } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_9.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_mod_cvar_get } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_mod_undef } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_mod_cvar_defined } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_mod_instance_methods } }, { .func_p = 1, { .func = (mrb_func_t)&sym_to_sym } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_mod_class_variables } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_mod_method_defined } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_mod_eqq } }, { .func_p = 1, { .func = (mrb_func_t)&sym_to_sym } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_mod_module_eval } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_mod_const_missing } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_mod_initialize } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_bob_init } }, { .func_p = 1, { .func = (mrb_func_t)&mod_define_method } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_mod_module_function } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_mod_included_modules } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_mod_attr_reader } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_mod_module_eval } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_bob_init } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_mod_remove_const } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_mod_append_features } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_mod_constants } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_mod_remove_method } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_mod_remove_cvar } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_mod_const_set } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_mod_include_p } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_mod_const_get } }, { .func_p = 1, { .func = (mrb_func_t)&sym_to_sym } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_mod_prepend_features } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_obj_clone } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_1 = { .n_buckets = 64, .size = 44, .n_occupied = 44, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_1_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_1_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_1_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_2_ed_flags[] = {
	0xaa, 0x0a,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_2_keys[] = {
	0, 0, 0, 0, 0, 0, 50, 56,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_2_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_mod_s_constants } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_mod_s_nesting } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_2 = { .n_buckets = 8, .size = 2, .n_occupied = 2, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_2_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_2_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_2_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_3_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_3_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_3_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_3 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_3_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_3_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_3_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_4_ed_flags[] = {
	0x88, 0x82, 0x0a, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_4_keys[] = {
	10, 0, 9, 0, 0, 11, 14, 0, 0, 0, 8, 13, 0, 0, 0, 12,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_4_vals[] = {
	{ .func_p = 1, { .func = (mrb_func_t)&mrb_obj_equal_m } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_bob_not } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_obj_not_equal_m } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_obj_instance_eval } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_bob_init } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_f_send } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_obj_hash } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_4 = { .n_buckets = 16, .size = 7, .n_occupied = 7, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_4_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_4_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_4_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_5_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_5_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_5_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_5 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_5_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_5_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_5_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_6_ed_flags[] = {
	0x80, 0x20,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_6_keys[] = {
	15, 17, 8, 0, 16, 26, 0, 21,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_6_vals[] = {
	{ .func_p = 1, { .func = (mrb_func_t)&mrb_instance_new } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_bob_init } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_class_initialize } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_class_superclass } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_6 = { .n_buckets = 8, .size = 6, .n_occupied = 6, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_6_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_6_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_6_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_7_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_7_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_7_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_7 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_7_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_7_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_7_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_8_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_8_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_8_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_8 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_8_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_8_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_8_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_9_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_9_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_9_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_9 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_9_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_9_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_9_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_10_ed_flags[] = {
	0x88, 0xa2, 0x88, 0x22,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_10_keys[] = {
	138, 0, 140, 0, 0, 139, 0, 0, 42, 0, 8, 0, 0, 43, 0, 137,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_10_vals[] = {
	{ .func_p = 1, { .func = (mrb_func_t)&exc_message } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&exc_set_backtrace } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_exc_backtrace } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&exc_to_s } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&exc_initialize } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&exc_inspect } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&exc_exception } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_10 = { .n_buckets = 16, .size = 7, .n_occupied = 7, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_10_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_10_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_10_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_11_ed_flags[] = {
	0xaa, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_11_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 137,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_11_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_instance_new } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_11 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_11_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_11_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_11_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_12_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_12_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_12_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_12 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_12_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_12_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_12_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_13_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_13_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_13_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_13 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_13_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_13_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_13_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_14_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_14_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_14_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_14 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_14_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_14_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_14_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_15_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_15_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_15_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_15 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_15_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_15_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_15_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_16_ed_flags[] = {
	0x82, 0xa8,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_16_keys[] = {
	0, 251, 8, 0, 373, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_16_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_23.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_187.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_188.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_16 = { .n_buckets = 8, .size = 3, .n_occupied = 3, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_16_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_16_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_16_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_17_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_17_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_17_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_17 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_17_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_17_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_17_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_18_ed_flags[] = {
	0xa8, 0xa0,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_18_keys[] = {
	42, 0, 0, 0, 53, 43, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_18_vals[] = {
	{ .func_p = 1, { .func = (mrb_func_t)&inspect_main } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&top_define_method } }, { .func_p = 1, { .func = (mrb_func_t)&inspect_main } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_18 = { .n_buckets = 8, .size = 3, .n_occupied = 3, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_18_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_18_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_18_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_19_ed_flags[] = {
	0xaa, 0xa8,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_19_keys[] = {
	0, 0, 0, 0, 432, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_19_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_32.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_19 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_19_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_19_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_19_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_20_ed_flags[] = {
	0x22, 0x00, 0x80, 0x20, 0x0a, 0x08, 0x80, 0xa0, 0x20, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x02, 0x80, 0x02, 0x00, 0x00, 0x08, 0x82, 0x00, 0x22, 0xa8, 0xa0, 0x88, 0x28, 0x20, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_20_keys[] = {
	0, 414, 0, 121, 80, 415, 120, 439, 42, 123, 436, 0, 122, 43, 0, 437,
	0, 0, 438, 124, 313, 0, 125, 312, 165, 126, 433, 0, 127, 435, 0, 0,
	10, 128, 0, 115, 310, 129, 114, 311, 0, 113, 8, 130, 112, 309, 405, 131,
	133, 448, 434, 118, 307, 132, 119, 306, 308, 305, 116, 135, 117, 304, 280, 134,
	440, 447, 109, 418, 0, 446, 442, 108, 111, 416, 419, 0, 0, 110, 417, 441,
	299, 155, 104, 423, 154, 443, 203, 105, 421, 0, 422, 153, 0, 107, 152, 0,
	79, 300, 424, 420, 0, 444, 0, 425, 426, 0, 0, 0, 302, 427, 0, 0,
	74, 0, 429, 0, 445, 0, 0, 294, 428, 431, 0, 25, 0, 430, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_20_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_dump } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_intern } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_replace } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_getbyte } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_index_m } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_33.proc } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_to_s } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_replace } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_34.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_size } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_inspect } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_36.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_38.proc } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_reverse } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_40.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_reverse_bang } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_42.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_43.proc } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_rindex } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_44.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_size } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_47.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_equal_m } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_aref_m } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_chop } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_51.proc } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_split_m } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_chomp_bang } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_53.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_chomp } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_init } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_to_f } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_capitalize_bang } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_55.proc } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_chr } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_to_i } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_upcase } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_59.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_61.proc } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_downcase_bang } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_64.proc } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_to_s } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_empty_p } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_66.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_69.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_71.proc } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_chop_bang } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_bytes } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_downcase } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_87.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_89.proc } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_upcase_bang } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_93.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_59.proc } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_times } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_swapcase_bang } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_94.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_96.proc } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_plus_m } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_capitalize } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_setbyte } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_swapcase } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_aref_m } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_byteslice } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_100.proc } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_succ } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_concat_m } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_intern } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_oct } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_104.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_106.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_107.proc } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_cmp_m } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_end_with } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_hex } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_108.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_bytesize } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_concat_m } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_hash_m } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_succ } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_lines } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_start_with } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_116.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_succ_bang } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_succ_bang } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_upto } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_ord } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_eql } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_del_prefix } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_120.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_124.proc } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_del_prefix_bang } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_del_suffix } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_include } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_str_del_suffix_bang } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_20 = { .n_buckets = 128, .size = 95, .n_occupied = 95, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_20_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_20_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_20_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_21_ed_flags[] = {
	0x00, 0x88,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_21_keys[] = {
	10, 190, 266, 192, 191, 0, 189, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_21_vals[] = {
	{ .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_128.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_129.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_133.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_134.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_138.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_142.proc } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_21 = { .n_buckets = 8, .size = 6, .n_occupied = 6, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_21_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_21_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_21_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_22_ed_flags[] = {
	0xaa, 0xa2,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_22_keys[] = {
	0, 0, 0, 0, 0, 110, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_22_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_ary_s_create } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_22 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_22_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_22_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_22_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_23_ed_flags[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x28, 0x02, 0x28, 0x80, 0x8a, 0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_23_keys[] = {
	256, 158, 109, 162, 80, 159, 120, 108, 160, 123, 163, 156, 122, 110, 157, 257,
	161, 155, 167, 124, 154, 259, 125, 166, 165, 126, 105, 153, 127, 164, 152, 258,
	128, 10, 168, 0, 42, 0, 0, 169, 0, 43, 8, 264, 250, 0, 0, 263,
	74, 260, 265, 0, 0, 0, 119, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_23_vals[] = {
	{ .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_149.proc } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_ary_join_m } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_ary_times } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_ary_push_m } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_ary_replace_m } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_ary_last } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_ary_index_m } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_ary_plus } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_ary_pop } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_ary_replace_m } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_ary_shift } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_ary_delete_at } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_ary_size } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_ary_aget } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_ary_first } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_150.proc } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_ary_push_m } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_ary_concat_m } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_ary_cmp } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_ary_reverse } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_ary_clear } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_151.proc } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_ary_reverse_bang } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_ary_eq } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_ary_unshift_m } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_ary_rindex_m } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_156.proc } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_ary_aset } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_ary_size } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_ary_unshift_m } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_ary_push_m } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_150.proc } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_ary_aget } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_157.proc } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_ary_index_m } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_158.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_ary_svalue } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_158.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_160.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_163.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_146.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_164.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_165.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_166.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_167.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_ary_empty_p } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_23 = { .n_buckets = 64, .size = 46, .n_occupied = 46, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_23_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_23_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_23_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_24_ed_flags[] = {
	0x20, 0xa0, 0x00, 0x0a, 0x80, 0x20, 0x0a, 0x08,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_24_keys[] = {
	262, 276, 0, 79, 277, 267, 0, 0, 280, 180, 281, 278, 0, 0, 279, 265,
	271, 273, 283, 0, 272, 270, 0, 282, 0, 0, 269, 275, 25, 0, 274, 268,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_24_vals[] = {
	{ .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_170.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_171.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_173.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_171.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_174.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_175.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_176.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_177.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_178.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_179.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_180.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_181.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_182.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_183.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_183.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_182.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_184.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_170.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_185.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_176.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_184.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_186.proc } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_24 = { .n_buckets = 32, .size = 22, .n_occupied = 22, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_24_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_24_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_24_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_25_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_25_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_25_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_25 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_25_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_25_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_25_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_26_ed_flags[] = {
	0x8a, 0x8a,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_26_keys[] = {
	0, 0, 8, 0, 0, 0, 253, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_26_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_190.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_191.proc } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_26 = { .n_buckets = 8, .size = 2, .n_occupied = 2, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_26_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_26_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_26_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_27_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_27_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_27_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_27 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_27_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_27_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_27_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_28_ed_flags[] = {
	0x82, 0xa0, 0x28, 0x80,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_28_keys[] = {
	0, 219, 222, 0, 218, 223, 0, 0, 224, 0, 0, 217, 220, 225, 221, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_28_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&gc_disable } }, { .func_p = 1, { .func = (mrb_func_t)&gc_step_ratio_get } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&gc_enable } }, { .func_p = 1, { .func = (mrb_func_t)&gc_step_ratio_set } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&gc_generational_mode_set } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&gc_start } }, { .func_p = 1, { .func = (mrb_func_t)&gc_interval_ratio_get } }, { .func_p = 1, { .func = (mrb_func_t)&gc_generational_mode_get } }, { .func_p = 1, { .func = (mrb_func_t)&gc_interval_ratio_set } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_28 = { .n_buckets = 16, .size = 9, .n_occupied = 9, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_28_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_28_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_28_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_29_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_29_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_29_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_29 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_29_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_29_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_29_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_30_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_30_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_30_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_30 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_30_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_30_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_30_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_31_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_31_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_31_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_31 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_31_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_31_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_31_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_32_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_32_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_32_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_32 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_32_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_32_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_32_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_33_ed_flags[] = {
	0xaa, 0x88,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_33_keys[] = {
	0, 0, 0, 0, 255, 0, 375, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_33_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_200.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_202.proc } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_33 = { .n_buckets = 8, .size = 2, .n_occupied = 2, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_33_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_33_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_33_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_34_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_34_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_34_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_34 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_34_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_34_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_34_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_35_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_35_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_35_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_35 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_35_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_35_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_35_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_36_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_36_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_36_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_36 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_36_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_36_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_36_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_37_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_37_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_37_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_37 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_37_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_37_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_37_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_38_ed_flags[] = {
	0xa8, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_38_keys[] = {
	15, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_38_vals[] = {
	{ .func_p = 1, { .func = (mrb_func_t)&mrb_proc_s_new } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_38 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_38_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_38_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_38_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_39_ed_flags[] = {
	0xa2, 0x80,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_39_keys[] = {
	0, 148, 0, 0, 80, 149, 110, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_39_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_proc_arity } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_proc_init_copy } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_210.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_210.proc } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_39 = { .n_buckets = 8, .size = 4, .n_occupied = 4, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_39_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_39_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_39_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_40_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_40_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_40_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_40 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_40_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_40_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_40_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_41_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_41_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_41_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_41 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_41_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_41_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_41_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_42_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_42_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_42_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_42 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_42_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_42_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_42_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_43_ed_flags[] = {
	0x2a, 0x08, 0x80, 0x00, 0x28, 0x80, 0x22, 0xa0, 0x80, 0xa8, 0x08, 0x80, 0x08, 0x08, 0x20, 0x20,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_43_keys[] = {
	0, 0, 0, 182, 80, 0, 183, 163, 42, 180, 123, 0, 122, 110, 43, 181,
	259, 0, 0, 179, 154, 260, 178, 0, 0, 177, 0, 153, 127, 176, 0, 0,
	10, 286, 290, 0, 287, 0, 0, 0, 288, 0, 8, 284, 250, 171, 285, 0,
	74, 0, 173, 289, 282, 0, 184, 119, 172, 175, 0, 25, 281, 174, 0, 73,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_43_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_hash_has_value } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_215.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_hash_values } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_hash_shift } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_217.proc } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_hash_has_key } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_215.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_hash_size_m } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_hash_aget } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_217.proc } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_hash_aset } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_219.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_hash_keys } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_hash_clear } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_225.proc } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_hash_has_key } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_hash_has_value } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_hash_aset } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_hash_size_m } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_hash_has_key } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_226.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_227.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_229.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_230.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_231.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_hash_init } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_232.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_233.proc } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_hash_default } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_234.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_235.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_hash_default_proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_236.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_237.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&sym_to_sym } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_hash_empty_p } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_hash_set_default } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_hash_delete } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_hash_has_key } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_238.proc } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_hash_set_default_proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_hash_dup } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_43 = { .n_buckets = 64, .size = 42, .n_occupied = 42, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_43_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_43_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_43_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_44_ed_flags[] = {
	0xaa, 0xa8, 0x28, 0x00, 0x82, 0x28, 0x28, 0x82,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_44_keys[] = {
	0, 0, 0, 0, 405, 0, 0, 0, 298, 0, 0, 406, 412, 299, 407, 413,
	0, 411, 301, 0, 410, 0, 0, 300, 303, 0, 0, 409, 0, 302, 408, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_44_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_int_chr } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_241.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_int_allbits } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_242.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_243.proc } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_int_anybits } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_244.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_245.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_246.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_247.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_243.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_248.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_251.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_252.proc } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_int_nobits } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_44 = { .n_buckets = 32, .size = 15, .n_occupied = 15, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_44_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_44_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_44_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_45_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_45_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_45_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_45 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_45_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_45_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_45_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_46_ed_flags[] = {
	0xa0, 0x80, 0x80, 0x80, 0xa8, 0xa8, 0x2a, 0x88,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_46_keys[] = {
	10, 79, 0, 0, 159, 80, 55, 0, 42, 180, 8, 0, 250, 43, 157, 0,
	74, 0, 0, 0, 213, 0, 0, 0, 0, 0, 0, 214, 25, 0, 215, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_46_vals[] = {
	{ .func_p = 1, { .func = (mrb_func_t)&mrb_range_eq } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_255.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_range_end } }, { .func_p = 1, { .func = (mrb_func_t)&range_initialize_copy } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_range_include } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&range_to_s } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_range_include } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_range_initialize } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_256.proc } }, { .func_p = 1, { .func = (mrb_func_t)&range_inspect } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_range_beg } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&range_eql } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_range_beg } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_range_end } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_range_include } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_range_excl } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_46 = { .n_buckets = 32, .size = 16, .n_occupied = 16, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_46_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_46_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_46_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_47_ed_flags[] = {
	0xa8, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_47_keys[] = {
	15, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_47_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_47 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_47_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_47_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_47_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_48_ed_flags[] = {
	0x0a, 0x0a, 0xa2, 0xa8, 0x88, 0x22, 0x82, 0xa8,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_48_keys[] = {
	0, 0, 296, 188, 0, 0, 189, 297, 0, 190, 0, 0, 191, 0, 0, 0,
	192, 0, 295, 0, 0, 193, 0, 105, 0, 187, 194, 0, 186, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_48_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_263.proc } }, { .func_p = 1, { .func = (mrb_func_t)&num_div } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&num_lt } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_264.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&num_le } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&num_gt } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&num_ge } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_265.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&num_finite_p } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&num_cmp } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&num_div } }, { .func_p = 1, { .func = (mrb_func_t)&num_infinite_p } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&num_pow } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_48 = { .n_buckets = 32, .size = 13, .n_occupied = 13, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_48_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_48_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_48_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_49_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_49_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_49_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_49 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_49_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_49_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_49_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_50_ed_flags[] = {
	0x0a, 0x22, 0x88, 0x22, 0xa8, 0xa2, 0x82, 0x88, 0xa0, 0xa0, 0x0a, 0x2a, 0x88, 0xa2, 0x8a, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_50_keys[] = {
	0, 0, 109, 60, 0, 206, 0, 108, 42, 0, 205, 0, 0, 43, 0, 204,
	202, 0, 0, 0, 0, 203, 0, 0, 0, 59, 200, 0, 58, 0, 152, 0,
	10, 197, 0, 0, 208, 196, 0, 0, 0, 0, 199, 130, 0, 0, 0, 131,
	74, 0, 198, 0, 0, 193, 0, 0, 0, 0, 194, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_50_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&flo_mul } }, { .func_p = 1, { .func = (mrb_func_t)&flo_or } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&flo_divmod } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&flo_plus } }, { .func_p = 1, { .func = (mrb_func_t)&flo_to_s } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&flo_lshift } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&flo_to_s } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&flo_rev } }, { .func_p = 1, { .func = (mrb_func_t)&flo_minus } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&flo_mod } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&flo_xor } }, { .func_p = 1, { .func = (mrb_func_t)&flo_truncate } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&flo_and } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&flo_rshift } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&flo_eq } }, { .func_p = 1, { .func = (mrb_func_t)&flo_ceil } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&flo_nan_p } }, { .func_p = 1, { .func = (mrb_func_t)&flo_truncate } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&flo_round } }, { .func_p = 1, { .func = (mrb_func_t)&sym_to_sym } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&flo_truncate } }, { .func_p = 1, { .func = (mrb_func_t)&flo_eql } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&flo_floor } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&flo_finite_p } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&flo_infinite_p } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_50 = { .n_buckets = 64, .size = 25, .n_occupied = 25, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_50_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_50_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_50_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_51_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_51_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_51_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_51 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_51_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_51_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_51_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_52_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_52_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_52_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_52 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_52_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_52_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_52_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_53_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_53_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_53_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_53 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_53_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_53_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_53_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_54_ed_flags[] = {
	0x80, 0x80, 0x08, 0x2a, 0x80, 0x00, 0x00, 0x08,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_54_keys[] = {
	384, 394, 396, 0, 404, 385, 395, 0, 403, 0, 386, 392, 0, 0, 0, 387,
	389, 399, 393, 0, 400, 388, 381, 401, 398, 382, 391, 397, 383, 0, 402, 390,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_54_vals[] = {
	{ .func_p = 1, { .func = (mrb_func_t)&math_asin } }, { .func_p = 1, { .func = (mrb_func_t)&math_exp } }, { .func_p = 1, { .func = (mrb_func_t)&math_log2 } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&math_erfc } }, { .func_p = 1, { .func = (mrb_func_t)&math_acos } }, { .func_p = 1, { .func = (mrb_func_t)&math_log } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&math_erf } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&math_atan } }, { .func_p = 1, { .func = (mrb_func_t)&math_acosh } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&math_atan2 } }, { .func_p = 1, { .func = (mrb_func_t)&math_cosh } }, { .func_p = 1, { .func = (mrb_func_t)&math_cbrt } }, { .func_p = 1, { .func = (mrb_func_t)&math_atanh } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&math_frexp } }, { .func_p = 1, { .func = (mrb_func_t)&math_sinh } }, { .func_p = 1, { .func = (mrb_func_t)&math_sin } }, { .func_p = 1, { .func = (mrb_func_t)&math_ldexp } }, { .func_p = 1, { .func = (mrb_func_t)&math_sqrt } }, { .func_p = 1, { .func = (mrb_func_t)&math_cos } }, { .func_p = 1, { .func = (mrb_func_t)&math_asinh } }, { .func_p = 1, { .func = (mrb_func_t)&math_log10 } }, { .func_p = 1, { .func = (mrb_func_t)&math_tan } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&math_hypot } }, { .func_p = 1, { .func = (mrb_func_t)&math_tanh } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_54 = { .n_buckets = 32, .size = 24, .n_occupied = 24, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_54_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_54_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_54_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_55_ed_flags[] = {
	0x80, 0x80, 0x08, 0x2a, 0x80, 0x00, 0x00, 0x08,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_55_keys[] = {
	384, 394, 396, 0, 404, 385, 395, 0, 403, 0, 386, 392, 0, 0, 0, 387,
	389, 399, 393, 0, 400, 388, 381, 401, 398, 382, 391, 397, 383, 0, 402, 390,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_55_vals[] = {
	{ .func_p = 1, { .func = (mrb_func_t)&math_asin } }, { .func_p = 1, { .func = (mrb_func_t)&math_exp } }, { .func_p = 1, { .func = (mrb_func_t)&math_log2 } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&math_erfc } }, { .func_p = 1, { .func = (mrb_func_t)&math_acos } }, { .func_p = 1, { .func = (mrb_func_t)&math_log } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&math_erf } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&math_atan } }, { .func_p = 1, { .func = (mrb_func_t)&math_acosh } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&math_atan2 } }, { .func_p = 1, { .func = (mrb_func_t)&math_cosh } }, { .func_p = 1, { .func = (mrb_func_t)&math_cbrt } }, { .func_p = 1, { .func = (mrb_func_t)&math_atanh } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&math_frexp } }, { .func_p = 1, { .func = (mrb_func_t)&math_sinh } }, { .func_p = 1, { .func = (mrb_func_t)&math_sin } }, { .func_p = 1, { .func = (mrb_func_t)&math_ldexp } }, { .func_p = 1, { .func = (mrb_func_t)&math_sqrt } }, { .func_p = 1, { .func = (mrb_func_t)&math_cos } }, { .func_p = 1, { .func = (mrb_func_t)&math_asinh } }, { .func_p = 1, { .func = (mrb_func_t)&math_log10 } }, { .func_p = 1, { .func = (mrb_func_t)&math_tan } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&math_hypot } }, { .func_p = 1, { .func = (mrb_func_t)&math_tanh } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_55 = { .n_buckets = 32, .size = 24, .n_occupied = 24, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_55_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_55_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_55_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_56_ed_flags[] = {
	0xa8, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_56_keys[] = {
	15, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_56_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_56 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_56_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_56_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_56_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_57_ed_flags[] = {
	0x20, 0xa0,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_57_keys[] = {
	42, 59, 0, 60, 58, 43, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_57_vals[] = {
	{ .func_p = 1, { .func = (mrb_func_t)&true_to_s } }, { .func_p = 1, { .func = (mrb_func_t)&true_xor } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_true } }, { .func_p = 1, { .func = (mrb_func_t)&false_xor } }, { .func_p = 1, { .func = (mrb_func_t)&true_to_s } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_57 = { .n_buckets = 8, .size = 5, .n_occupied = 5, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_57_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_57_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_57_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_58_ed_flags[] = {
	0xa8, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_58_keys[] = {
	15, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_58_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_58 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_58_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_58_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_58_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_59_ed_flags[] = {
	0x20, 0xa0,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_59_keys[] = {
	42, 59, 0, 60, 58, 43, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_59_vals[] = {
	{ .func_p = 1, { .func = (mrb_func_t)&false_to_s } }, { .func_p = 1, { .func = (mrb_func_t)&false_xor } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&false_xor } }, { .func_p = 1, { .func = (mrb_func_t)&false_and } }, { .func_p = 1, { .func = (mrb_func_t)&false_to_s } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_59 = { .n_buckets = 8, .size = 5, .n_occupied = 5, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_59_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_59_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_59_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_60_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_60_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_60_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_60 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_60_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_60_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_60_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_61_ed_flags[] = {
	0x08, 0x02,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_61_keys[] = {
	69, 0, 66, 150, 0, 65, 68, 67,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_61_vals[] = {
	{ .func_p = 1, { .func = (mrb_func_t)&mrb_f_raise } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_f_global_variables } }, { .func_p = 1, { .func = (mrb_func_t)&proc_lambda } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_f_block_given_p_m } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_local_variables } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_f_block_given_p_m } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_61 = { .n_buckets = 8, .size = 6, .n_occupied = 6, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_61_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_61_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_61_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_62_ed_flags[] = {
	0x20, 0x80, 0x08, 0x02, 0x20, 0xa0, 0x0a, 0x08, 0xa0, 0x00, 0x0a, 0x08, 0x00, 0x20, 0x00, 0x02,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_62_keys[] = {
	69, 81, 0, 292, 80, 68, 61, 0, 42, 0, 71, 83, 0, 43, 82, 70,
	259, 84, 0, 261, 85, 65, 0, 0, 0, 0, 66, 86, 463, 0, 87, 67,
	79, 91, 0, 0, 90, 78, 55, 291, 0, 0, 77, 89, 150, 0, 88, 76,
	74, 94, 98, 464, 95, 75, 0, 99, 96, 293, 72, 92, 0, 97, 93, 73,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_62_vals[] = {
	{ .func_p = 1, { .func = (mrb_func_t)&mrb_f_raise } }, { .func_p = 1, { .func = (mrb_func_t)&obj_is_instance_of } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_283.proc } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_obj_init_copy } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_local_variables } }, { .func_p = 1, { .func = (mrb_func_t)&false_and } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_any_to_s } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_obj_class_m } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_obj_ivar_get } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_obj_inspect } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_obj_ivar_defined } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_singleton_class } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_284.proc } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_obj_ivar_set } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_285.proc } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_obj_instance_variables } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_f_block_given_p_m } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_f_global_variables } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_obj_is_kind_of_m } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_f_sprintf } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_obj_is_kind_of_m } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_f_block_given_p_m } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_obj_hash } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_obj_protected_methods } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_obj_private_methods } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_obj_frozen } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_equal_m } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_287.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_obj_freeze } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_obj_hash } }, { .func_p = 1, { .func = (mrb_func_t)&proc_lambda } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_obj_public_methods } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_obj_extend_m } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_obj_equal_m } }, { .func_p = 1, { .func = (mrb_func_t)&obj_respond_to } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_obj_ceqq } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_f_sprintf } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_f_send } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_obj_equal_m } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_krn_class_defined } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_obj_singleton_methods_m } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_289.proc } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_obj_clone } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_obj_public_methods } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mod_define_singleton_method } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_obj_remove_instance_variable } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_obj_dup } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_62 = { .n_buckets = 64, .size = 47, .n_occupied = 47, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_62_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_62_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_62_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_63_ed_flags[] = {
	0xa8, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_63_keys[] = {
	15, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_63_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_63 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_63_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_63_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_63_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_64_ed_flags[] = {
	0x20, 0x80,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_64_keys[] = {
	42, 59, 0, 60, 58, 43, 61, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_64_vals[] = {
	{ .func_p = 1, { .func = (mrb_func_t)&nil_to_s } }, { .func_p = 1, { .func = (mrb_func_t)&false_xor } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&false_xor } }, { .func_p = 1, { .func = (mrb_func_t)&false_and } }, { .func_p = 1, { .func = (mrb_func_t)&nil_inspect } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_true } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_64 = { .n_buckets = 8, .size = 6, .n_occupied = 6, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_64_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_64_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_64_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_65_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_65_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_65_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_65 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_65_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_65_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_65_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_66_ed_flags[] = {
	0x88, 0xa2, 0x0a, 0x2a,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_66_keys[] = {
	197, 0, 131, 0, 0, 196, 0, 0, 0, 0, 199, 200, 0, 0, 0, 198,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_66_vals[] = {
	{ .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_298.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&sym_to_sym } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&sym_to_sym } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_299.proc } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_299.proc } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = (struct RProc *)&mrb_preset_object_299.proc } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_66 = { .n_buckets = 16, .size = 6, .n_occupied = 6, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_66_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_66_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_66_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_67_ed_flags[] = {
	0xa8, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_67_keys[] = {
	15, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_67_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_67 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_67_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_67_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_67_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_68_ed_flags[] = {
	0x08, 0x20, 0x08, 0x22, 0xa0, 0xa2, 0xa2, 0x88,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_68_keys[] = {
	10, 0, 109, 60, 405, 206, 0, 108, 42, 0, 205, 130, 0, 43, 0, 204,
	202, 74, 0, 0, 0, 203, 0, 0, 0, 59, 0, 0, 58, 0, 152, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_68_vals[] = {
	{ .func_p = 1, { .func = (mrb_func_t)&fix_equal } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&fix_mul } }, { .func_p = 1, { .func = (mrb_func_t)&fix_or } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_fixnum_chr } }, { .func_p = 1, { .func = (mrb_func_t)&fix_divmod } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&fix_plus } }, { .func_p = 1, { .func = (mrb_func_t)&fix_to_s } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&fix_rshift } }, { .func_p = 1, { .func = (mrb_func_t)&fix_to_f } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&fix_to_s } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&fix_rev } }, { .func_p = 1, { .func = (mrb_func_t)&fix_minus } }, { .func_p = 1, { .func = (mrb_func_t)&fix_eql } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&fix_mod } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&fix_xor } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&fix_and } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&fix_lshift } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_68 = { .n_buckets = 32, .size = 17, .n_occupied = 17, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_68_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_68_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_68_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_69_ed_flags[] = {
	0x2a, 0xa8,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_69_keys[] = {
	0, 0, 0, 470, 469, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_69_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&fiber_current } }, { .func_p = 1, { .func = (mrb_func_t)&fiber_yield } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_69 = { .n_buckets = 8, .size = 2, .n_occupied = 2, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_69_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_69_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_69_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_70_ed_flags[] = {
	0x00, 0x8a,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_70_keys[] = {
	10, 468, 8, 467, 0, 0, 466, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_70_vals[] = {
	{ .func_p = 1, { .func = (mrb_func_t)&fiber_eq } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_fiber_alive_p } }, { .func_p = 1, { .func = (mrb_func_t)&fiber_init } }, { .func_p = 1, { .func = (mrb_func_t)&fiber_transfer } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&fiber_resume } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_70 = { .n_buckets = 8, .size = 5, .n_occupied = 5, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_70_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_70_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_70_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_71_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_71_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_71_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_71 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_71_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_71_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_71_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_72_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_72_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_72_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_72 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_72_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_72_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_72_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_73_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_73_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_73_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_73 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_73_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_73_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_73_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_74_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_74_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_74_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_74 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_74_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_74_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_74_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_75_ed_flags[] = {
	0xa8, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_75_keys[] = {
	15, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_75_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_75 = { .n_buckets = 8, .size = 1, .n_occupied = 1, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_75_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_75_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_75_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_76_ed_flags[] = {
	0x08, 0x02,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_76_keys[] = {
	42, 0, 103, 104, 0, 43, 55, 105,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_76_vals[] = {
	{ .func_p = 1, { .func = (mrb_func_t)&mrb_sym_to_s } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&mrb_sym_to_s } }, { .func_p = 1, { .func = (mrb_func_t)&sym_to_sym } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 1, { .func = (mrb_func_t)&sym_inspect } }, { .func_p = 1, { .func = (mrb_func_t)&sym_equal } }, { .func_p = 1, { .func = (mrb_func_t)&sym_cmp } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_76 = { .n_buckets = 8, .size = 6, .n_occupied = 6, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_76_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_76_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_76_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_77_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_77_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_77_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_77 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_77_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_77_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_77_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_78_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_78_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_78_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_78 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_78_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_78_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_78_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_79_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_79_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_79_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_79 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_79_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_79_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_79_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_80_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_80_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_80_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_80 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_80_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_80_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_80_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_81_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_81_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_81_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_81 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_81_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_81_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_81_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_82_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_82_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_82_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_82 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_82_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_82_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_82_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_83_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_83_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_83_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_83 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_83_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_83_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_83_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_84_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_84_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_84_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_84 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_84_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_84_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_84_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_85_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_85_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_85_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_85 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_85_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_85_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_85_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_86_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_86_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_86_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_86 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_86_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_86_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_86_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_87_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_87_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_87_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_87 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_87_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_87_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_87_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_88_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_88_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_88_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_88 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_88_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_88_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_88_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_89_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_89_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_89_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_89 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_89_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_89_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_89_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_90_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_90_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_90_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_90 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_90_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_90_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_90_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_91_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_91_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_91_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_91 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_91_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_91_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_91_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_92_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_92_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_92_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_92 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_92_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_92_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_92_vals };

PRESET_DATA uint8_t mrb_preset_kh_mt_93_ed_flags[] = {
	0xaa, 0xaa,
};
PRESET_DATA mrb_sym mrb_preset_kh_mt_93_keys[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
};
PRESET_DATA mrb_method_t mrb_preset_kh_mt_93_vals[] = {
	{ .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, { .func_p = 0, { .proc = NULL } }, 
};
PRESET_DATA kh_mt_t mrb_preset_kh_mt_93 = { .n_buckets = 8, .size = 0, .n_occupied = 0, .ed_flags = (uint8_t *)&mrb_preset_kh_mt_93_ed_flags, .keys = (mrb_sym *)&mrb_preset_kh_mt_93_keys, .vals = (mrb_method_t *)&mrb_preset_kh_mt_93_vals };


PRESET_DATA mrb_value mrb_preset_stack_0[] = { 	{ .value = { .p = (void *)&mrb_preset_object_25 }, .tt = MRB_TT_OBJECT },
	{ .value = { .sym = (mrb_sym)203 }, .tt = MRB_TT_SYMBOL },
	{ .value = { .sym = (mrb_sym)203 }, .tt = MRB_TT_SYMBOL },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
	{ .value = { .i = 0 }, .tt = MRB_TT_FALSE },
};

PRESET_DATA mrb_callinfo mrb_preset_callinfo_0[] = {
	{ .mid = (mrb_sym)0, .proc = (struct RProc *)&mrb_preset_object_28.proc, .stackent = (mrb_value *)&mrb_preset_stack_0[0], .nregs = 3, .ridx = 0, .epos = 0, .env = NULL, .pc = NULL, .err = NULL, .argc = 0, .acc = 0, .target_class = (struct RClass *)&mrb_preset_object_0.klass },
	{ .mid = (mrb_sym)0, .proc = (struct RProc *)&mrb_preset_object_29.proc, .stackent = (mrb_value *)&mrb_preset_stack_0[0], .nregs = 3, .ridx = 0, .epos = 0, .env = NULL, .pc = (mrb_code *)&((uint8_t *)gem_mrblib_irep_mruby_sprintf)[64], .err = NULL, .argc = 0, .acc = 1, .target_class = (struct RClass *)&mrb_preset_object_30.klass },
	{ .mid = (mrb_sym)44, .proc = NULL, .stackent = (mrb_value *)&mrb_preset_stack_0[1], .nregs = 4, .ridx = 0, .epos = 0, .env = NULL, .pc = (mrb_code *)&((uint8_t *)gem_mrblib_irep_mruby_string_ext)[352], .err = NULL, .argc = 2, .acc = 1, .target_class = (struct RClass *)&mrb_preset_object_6.klass },
	{ .mid = (mrb_sym)250, .proc = (struct RProc *)&mrb_preset_object_146.proc, .stackent = (mrb_value *)&mrb_preset_stack_0[2], .nregs = 7, .ridx = 0, .epos = 0, .env = NULL, .pc = (mrb_code *)&((uint8_t *)mrblib_irep)[1204], .err = NULL, .argc = 0, .acc = 3, .target_class = (struct RClass *)&mrb_preset_object_147.klass },
	{ .mid = (mrb_sym)122, .proc = NULL, .stackent = (mrb_value *)&mrb_preset_stack_0[5], .nregs = 2, .ridx = 0, .epos = 0, .env = NULL, .pc = (mrb_code *)&((uint8_t *)mrblib_irep)[2620], .err = NULL, .argc = 0, .acc = 4, .target_class = (struct RClass *)&mrb_preset_object_147.klass },
	{ .mid = (mrb_sym)28, .proc = NULL, .stackent = (mrb_value *)&mrb_preset_stack_0[8], .nregs = 3, .ridx = 0, .epos = 0, .env = NULL, .pc = (mrb_code *)&((uint8_t *)mrblib_irep)[1280], .err = NULL, .argc = 1, .acc = 3, .target_class = (struct RClass *)&mrb_preset_object_6.klass },
	{ .mid = (mrb_sym)0, .proc = NULL, .stackent = NULL, .nregs = 0, .ridx = 0, .epos = 0, .env = NULL, .pc = NULL, .err = NULL, .argc = 0, .acc = 0, .target_class = NULL },
	{ .mid = (mrb_sym)0, .proc = NULL, .stackent = NULL, .nregs = 0, .ridx = 0, .epos = 0, .env = NULL, .pc = NULL, .err = NULL, .argc = 0, .acc = 0, .target_class = NULL },
	{ .mid = (mrb_sym)0, .proc = NULL, .stackent = NULL, .nregs = 0, .ridx = 0, .epos = 0, .env = NULL, .pc = NULL, .err = NULL, .argc = 0, .acc = 0, .target_class = NULL },
	{ .mid = (mrb_sym)0, .proc = NULL, .stackent = NULL, .nregs = 0, .ridx = 0, .epos = 0, .env = NULL, .pc = NULL, .err = NULL, .argc = 0, .acc = 0, .target_class = NULL },
	{ .mid = (mrb_sym)0, .proc = NULL, .stackent = NULL, .nregs = 0, .ridx = 0, .epos = 0, .env = NULL, .pc = NULL, .err = NULL, .argc = 0, .acc = 0, .target_class = NULL },
	{ .mid = (mrb_sym)0, .proc = NULL, .stackent = NULL, .nregs = 0, .ridx = 0, .epos = 0, .env = NULL, .pc = NULL, .err = NULL, .argc = 0, .acc = 0, .target_class = NULL },
	{ .mid = (mrb_sym)0, .proc = NULL, .stackent = NULL, .nregs = 0, .ridx = 0, .epos = 0, .env = NULL, .pc = NULL, .err = NULL, .argc = 0, .acc = 0, .target_class = NULL },
	{ .mid = (mrb_sym)0, .proc = NULL, .stackent = NULL, .nregs = 0, .ridx = 0, .epos = 0, .env = NULL, .pc = NULL, .err = NULL, .argc = 0, .acc = 0, .target_class = NULL },
	{ .mid = (mrb_sym)0, .proc = NULL, .stackent = NULL, .nregs = 0, .ridx = 0, .epos = 0, .env = NULL, .pc = NULL, .err = NULL, .argc = 0, .acc = 0, .target_class = NULL },
	{ .mid = (mrb_sym)0, .proc = NULL, .stackent = NULL, .nregs = 0, .ridx = 0, .epos = 0, .env = NULL, .pc = NULL, .err = NULL, .argc = 0, .acc = 0, .target_class = NULL },
	{ .mid = (mrb_sym)0, .proc = NULL, .stackent = NULL, .nregs = 0, .ridx = 0, .epos = 0, .env = NULL, .pc = NULL, .err = NULL, .argc = 0, .acc = 0, .target_class = NULL },
	{ .mid = (mrb_sym)0, .proc = NULL, .stackent = NULL, .nregs = 0, .ridx = 0, .epos = 0, .env = NULL, .pc = NULL, .err = NULL, .argc = 0, .acc = 0, .target_class = NULL },
	{ .mid = (mrb_sym)0, .proc = NULL, .stackent = NULL, .nregs = 0, .ridx = 0, .epos = 0, .env = NULL, .pc = NULL, .err = NULL, .argc = 0, .acc = 0, .target_class = NULL },
	{ .mid = (mrb_sym)0, .proc = NULL, .stackent = NULL, .nregs = 0, .ridx = 0, .epos = 0, .env = NULL, .pc = NULL, .err = NULL, .argc = 0, .acc = 0, .target_class = NULL },
	{ .mid = (mrb_sym)0, .proc = NULL, .stackent = NULL, .nregs = 0, .ridx = 0, .epos = 0, .env = NULL, .pc = NULL, .err = NULL, .argc = 0, .acc = 0, .target_class = NULL },
	{ .mid = (mrb_sym)0, .proc = NULL, .stackent = NULL, .nregs = 0, .ridx = 0, .epos = 0, .env = NULL, .pc = NULL, .err = NULL, .argc = 0, .acc = 0, .target_class = NULL },
	{ .mid = (mrb_sym)0, .proc = NULL, .stackent = NULL, .nregs = 0, .ridx = 0, .epos = 0, .env = NULL, .pc = NULL, .err = NULL, .argc = 0, .acc = 0, .target_class = NULL },
	{ .mid = (mrb_sym)0, .proc = NULL, .stackent = NULL, .nregs = 0, .ridx = 0, .epos = 0, .env = NULL, .pc = NULL, .err = NULL, .argc = 0, .acc = 0, .target_class = NULL },
	{ .mid = (mrb_sym)0, .proc = NULL, .stackent = NULL, .nregs = 0, .ridx = 0, .epos = 0, .env = NULL, .pc = NULL, .err = NULL, .argc = 0, .acc = 0, .target_class = NULL },
	{ .mid = (mrb_sym)0, .proc = NULL, .stackent = NULL, .nregs = 0, .ridx = 0, .epos = 0, .env = NULL, .pc = NULL, .err = NULL, .argc = 0, .acc = 0, .target_class = NULL },
	{ .mid = (mrb_sym)0, .proc = NULL, .stackent = NULL, .nregs = 0, .ridx = 0, .epos = 0, .env = NULL, .pc = NULL, .err = NULL, .argc = 0, .acc = 0, .target_class = NULL },
	{ .mid = (mrb_sym)0, .proc = NULL, .stackent = NULL, .nregs = 0, .ridx = 0, .epos = 0, .env = NULL, .pc = NULL, .err = NULL, .argc = 0, .acc = 0, .target_class = NULL },
	{ .mid = (mrb_sym)0, .proc = NULL, .stackent = NULL, .nregs = 0, .ridx = 0, .epos = 0, .env = NULL, .pc = NULL, .err = NULL, .argc = 0, .acc = 0, .target_class = NULL },
	{ .mid = (mrb_sym)0, .proc = NULL, .stackent = NULL, .nregs = 0, .ridx = 0, .epos = 0, .env = NULL, .pc = NULL, .err = NULL, .argc = 0, .acc = 0, .target_class = NULL },
	{ .mid = (mrb_sym)0, .proc = NULL, .stackent = NULL, .nregs = 0, .ridx = 0, .epos = 0, .env = NULL, .pc = NULL, .err = NULL, .argc = 0, .acc = 0, .target_class = NULL },
	{ .mid = (mrb_sym)0, .proc = NULL, .stackent = NULL, .nregs = 0, .ridx = 0, .epos = 0, .env = NULL, .pc = NULL, .err = NULL, .argc = 0, .acc = 0, .target_class = NULL },
};

PRESET_DATA struct mrb_context mrb_preset_context_0 = {
	.prev = (struct mrb_context *)0x00000000,
	.stack = (mrb_value *)&mrb_preset_stack_0[0],
	.stbase = (mrb_value *)mrb_preset_stack_0,
	.stend = (mrb_value *)&mrb_preset_stack_0[128],
	.ci = (mrb_callinfo *)&mrb_preset_callinfo_0[0],
	.cibase = (mrb_callinfo *)mrb_preset_callinfo_0,
	.ciend = (mrb_callinfo *)&mrb_preset_callinfo_0[32],
	.rescue = (mrb_code **)0x00000000,
	.rsize = 0,
	.ensure = (struct RProc **)0x00000000,
	.esize = 0, .eidx = 0,
	.status = (enum mrb_fiber_state)0,
	.vmexec = (mrb_bool)0,
	.fib = NULL,
};

PRESET_CONST RVALUE mrb_preset_object_0 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_10.klass, .gcnext = (struct RBasic *)&mrb_preset_object_327.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_0, .mt = (struct kh_mt *)&mrb_preset_kh_mt_93, .super = (struct RClass *)&mrb_preset_object_327.klass, } };
PRESET_CONST RVALUE mrb_preset_object_1 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0x12, .c = (struct RClass *)&mrb_preset_object_2.klass, .gcnext = (struct RBasic *)&mrb_preset_object_20.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_1, .mt = (struct kh_mt *)&mrb_preset_kh_mt_14, .super = (struct RClass *)&mrb_preset_object_14.klass, } };
PRESET_CONST RVALUE mrb_preset_object_2 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_14.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_2, .mt = (struct kh_mt *)&mrb_preset_kh_mt_7, .super = (struct RClass *)&mrb_preset_object_13.klass, } };
PRESET_CONST RVALUE mrb_preset_object_3 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0x9, .c = (struct RClass *)&mrb_preset_object_4.klass, .gcnext = (struct RBasic *)&mrb_preset_object_2.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_3, .mt = (struct kh_mt *)&mrb_preset_kh_mt_6, .super = (struct RClass *)&mrb_preset_object_6.klass, } };
PRESET_CONST RVALUE mrb_preset_object_4 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_6.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_4, .mt = (struct kh_mt *)&mrb_preset_kh_mt_0, .super = (struct RClass *)&mrb_preset_object_5.klass, } };
PRESET_CONST RVALUE mrb_preset_object_5 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_10.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_5, .mt = (struct kh_mt *)&mrb_preset_kh_mt_2, .super = (struct RClass *)&mrb_preset_object_10.klass, } };
PRESET_CONST RVALUE mrb_preset_object_6 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0xa, .c = (struct RClass *)&mrb_preset_object_5.klass, .gcnext = (struct RBasic *)&mrb_preset_object_5.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_6, .mt = (struct kh_mt *)&mrb_preset_kh_mt_1, .super = (struct RClass *)&mrb_preset_object_0.klass, } };
PRESET_CONST RVALUE mrb_preset_object_7 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_0 }, .upper = (struct RProc *)&mrb_preset_object_6.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_6.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_8 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_2 }, .upper = (struct RProc *)&mrb_preset_object_6.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_6.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_9 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_3 }, .upper = (struct RProc *)&mrb_preset_object_6.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_6.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_10 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_12.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_7, .mt = (struct kh_mt *)&mrb_preset_kh_mt_3, .super = (struct RClass *)&mrb_preset_object_11.klass, } };
PRESET_CONST RVALUE mrb_preset_object_11 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_3.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_8, .mt = (struct kh_mt *)&mrb_preset_kh_mt_5, .super = (struct RClass *)&mrb_preset_object_3.klass, } };
PRESET_CONST RVALUE mrb_preset_object_12 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_11.klass, .gcnext = (struct RBasic *)&mrb_preset_object_11.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_9, .mt = (struct kh_mt *)&mrb_preset_kh_mt_4, .super = NULL, } };
PRESET_CONST RVALUE mrb_preset_object_13 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_1.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_10, .mt = (struct kh_mt *)&mrb_preset_kh_mt_13, .super = (struct RClass *)&mrb_preset_object_16.klass, } };
PRESET_CONST RVALUE mrb_preset_object_14 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0x12, .c = (struct RClass *)&mrb_preset_object_13.klass, .gcnext = (struct RBasic *)&mrb_preset_object_16.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_11, .mt = (struct kh_mt *)&mrb_preset_kh_mt_8, .super = (struct RClass *)&mrb_preset_object_15.klass, } };
PRESET_CONST RVALUE mrb_preset_object_15 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0x12, .c = (struct RClass *)&mrb_preset_object_16.klass, .gcnext = (struct RBasic *)&mrb_preset_object_13.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_12, .mt = (struct kh_mt *)&mrb_preset_kh_mt_12, .super = (struct RClass *)&mrb_preset_object_18.klass, } };
PRESET_CONST RVALUE mrb_preset_object_16 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_18.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_13, .mt = (struct kh_mt *)&mrb_preset_kh_mt_9, .super = (struct RClass *)&mrb_preset_object_17.klass, } };
PRESET_CONST RVALUE mrb_preset_object_17 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_15.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_14, .mt = (struct kh_mt *)&mrb_preset_kh_mt_11, .super = (struct RClass *)&mrb_preset_object_10.klass, } };
PRESET_CONST RVALUE mrb_preset_object_18 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0x12, .c = (struct RClass *)&mrb_preset_object_17.klass, .gcnext = (struct RBasic *)&mrb_preset_object_17.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_15, .mt = (struct kh_mt *)&mrb_preset_kh_mt_10, .super = (struct RClass *)&mrb_preset_object_0.klass, } };
PRESET_CONST RVALUE mrb_preset_object_19 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0x12, .c = (struct RClass *)&mrb_preset_object_20.klass, .gcnext = (struct RBasic *)&mrb_preset_object_195.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_16, .mt = (struct kh_mt *)&mrb_preset_kh_mt_26, .super = (struct RClass *)&mrb_preset_object_22.klass, } };
PRESET_CONST RVALUE mrb_preset_object_20 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_22.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_17, .mt = (struct kh_mt *)&mrb_preset_kh_mt_15, .super = (struct RClass *)&mrb_preset_object_21.klass, } };
PRESET_CONST RVALUE mrb_preset_object_21 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_19.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_18, .mt = (struct kh_mt *)&mrb_preset_kh_mt_25, .super = (struct RClass *)&mrb_preset_object_16.klass, } };
PRESET_CONST RVALUE mrb_preset_object_22 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0x12, .c = (struct RClass *)&mrb_preset_object_21.klass, .gcnext = (struct RBasic *)&mrb_preset_object_27.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_19, .mt = (struct kh_mt *)&mrb_preset_kh_mt_16, .super = (struct RClass *)&mrb_preset_object_15.klass, } };
PRESET_CONST RVALUE mrb_preset_object_23 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0xc80, .c = NULL, .gcnext = NULL, .body = { .func = (mrb_func_t)attr_reader }, .upper = NULL, .e = { .env = (struct REnv *)&mrb_preset_object_24.env }, } };
PRESET_DATA RVALUE mrb_preset_object_24 = { .env = { .tt = MRB_TT_ENV, .color = 4, .flags = 0x100801, .c = NULL, .gcnext = NULL, .stack = (mrb_value *)&mrb_preset_env_stacks_24, .cxt = (struct mrb_context *)&mrb_preset_context_0, .mid = (mrb_sym)40, } };
PRESET_CONST RVALUE mrb_preset_object_25 = { .object = { .tt = MRB_TT_OBJECT, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_26.klass, .gcnext = (struct RBasic *)&mrb_preset_object_31.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_20, } };
PRESET_CONST RVALUE mrb_preset_object_26 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_27.klass, .gcnext = (struct RBasic *)&mrb_preset_object_25.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_21, .mt = (struct kh_mt *)&mrb_preset_kh_mt_18, .super = (struct RClass *)&mrb_preset_object_0.klass, } };
PRESET_CONST RVALUE mrb_preset_object_27 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_26.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_22, .mt = (struct kh_mt *)&mrb_preset_kh_mt_17, .super = (struct RClass *)&mrb_preset_object_10.klass, } };
PRESET_CONST RVALUE mrb_preset_object_28 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x0, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_5 }, .upper = (struct RProc *)&mrb_preset_object_0.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_0.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_29 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x800, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_6 }, .upper = (struct RProc *)&mrb_preset_object_30.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_30.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_30 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0x10, .c = (struct RClass *)&mrb_preset_object_31.klass, .gcnext = (struct RBasic *)&mrb_preset_object_127.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_23, .mt = (struct kh_mt *)&mrb_preset_kh_mt_20, .super = (struct RClass *)&mrb_preset_object_126.klass, } };
PRESET_CONST RVALUE mrb_preset_object_31 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_30.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_24, .mt = (struct kh_mt *)&mrb_preset_kh_mt_19, .super = (struct RClass *)&mrb_preset_object_10.klass, } };
PRESET_CONST RVALUE mrb_preset_object_32 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_8 }, .upper = (struct RProc *)&mrb_preset_object_31.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_31.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_33 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_9 }, .upper = (struct RProc *)&mrb_preset_object_30.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_30.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_34 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_10 }, .upper = (struct RProc *)&mrb_preset_object_30.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_30.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_35 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 26,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_0 } }, } };
PRESET_CONST RVALUE mrb_preset_object_36 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_11 }, .upper = (struct RProc *)&mrb_preset_object_30.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_30.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_37 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 26,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_0 } }, } };
PRESET_CONST RVALUE mrb_preset_object_38 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_12 }, .upper = (struct RProc *)&mrb_preset_object_30.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_30.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_39 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 26,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_0 } }, } };
PRESET_CONST RVALUE mrb_preset_object_40 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_13 }, .upper = (struct RProc *)&mrb_preset_object_30.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_30.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_41 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 31,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_1 } }, } };
PRESET_CONST RVALUE mrb_preset_object_42 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_14 }, .upper = (struct RProc *)&mrb_preset_object_30.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_30.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_43 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_15 }, .upper = (struct RProc *)&mrb_preset_object_30.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_30.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_44 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_16 }, .upper = (struct RProc *)&mrb_preset_object_30.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_30.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_45 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 6,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_2 } }, } };
PRESET_CONST RVALUE mrb_preset_object_46 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 0,.aux = { .capa = 0 }, .ptr = NULL } }, } };
PRESET_CONST RVALUE mrb_preset_object_47 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_17 }, .upper = (struct RProc *)&mrb_preset_object_30.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_30.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_48 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 6,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_2 } }, } };
PRESET_CONST RVALUE mrb_preset_object_49 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 7,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_2 } }, } };
PRESET_CONST RVALUE mrb_preset_object_50 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 0,.aux = { .capa = 0 }, .ptr = NULL } }, } };
PRESET_CONST RVALUE mrb_preset_object_51 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_18 }, .upper = (struct RProc *)&mrb_preset_object_30.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_30.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_52 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 26,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_0 } }, } };
PRESET_CONST RVALUE mrb_preset_object_53 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_19 }, .upper = (struct RProc *)&mrb_preset_object_30.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_30.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_54 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 0,.aux = { .capa = 0 }, .ptr = NULL } }, } };
PRESET_CONST RVALUE mrb_preset_object_55 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_21 }, .upper = (struct RProc *)&mrb_preset_object_30.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_30.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_56 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 33,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_3 } }, } };
PRESET_CONST RVALUE mrb_preset_object_57 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 13,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_4 } }, } };
PRESET_CONST RVALUE mrb_preset_object_58 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 0,.aux = { .capa = 0 }, .ptr = NULL } }, } };
PRESET_CONST RVALUE mrb_preset_object_59 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_22 }, .upper = (struct RProc *)&mrb_preset_object_30.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_30.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_60 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 0,.aux = { .capa = 0 }, .ptr = NULL } }, } };
PRESET_CONST RVALUE mrb_preset_object_61 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_25 }, .upper = (struct RProc *)&mrb_preset_object_30.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_30.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_62 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 7,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_2 } }, } };
PRESET_CONST RVALUE mrb_preset_object_63 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 0,.aux = { .capa = 0 }, .ptr = NULL } }, } };
PRESET_CONST RVALUE mrb_preset_object_64 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_26 }, .upper = (struct RProc *)&mrb_preset_object_30.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_30.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_65 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 26,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_0 } }, } };
PRESET_CONST RVALUE mrb_preset_object_66 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_27 }, .upper = (struct RProc *)&mrb_preset_object_30.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_30.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_67 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 25,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_3 } }, } };
PRESET_CONST RVALUE mrb_preset_object_68 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 0,.aux = { .capa = 0 }, .ptr = NULL } }, } };
PRESET_CONST RVALUE mrb_preset_object_69 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_28 }, .upper = (struct RProc *)&mrb_preset_object_30.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_30.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_70 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 24,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_5 } }, } };
PRESET_CONST RVALUE mrb_preset_object_71 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_29 }, .upper = (struct RProc *)&mrb_preset_object_30.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_30.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_72 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 0,.aux = { .capa = 0 }, .ptr = NULL } }, } };
PRESET_CONST RVALUE mrb_preset_object_73 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 1,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_6 } }, } };
PRESET_CONST RVALUE mrb_preset_object_74 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 1,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_7 } }, } };
PRESET_CONST RVALUE mrb_preset_object_75 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 1,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_8 } }, } };
PRESET_CONST RVALUE mrb_preset_object_76 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 1,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_9 } }, } };
PRESET_CONST RVALUE mrb_preset_object_77 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 1,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_10 } }, } };
PRESET_CONST RVALUE mrb_preset_object_78 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 1,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_11 } }, } };
PRESET_CONST RVALUE mrb_preset_object_79 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 1,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_12 } }, } };
PRESET_CONST RVALUE mrb_preset_object_80 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 1,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_13 } }, } };
PRESET_CONST RVALUE mrb_preset_object_81 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 1,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_14 } }, } };
PRESET_CONST RVALUE mrb_preset_object_82 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 1,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_15 } }, } };
PRESET_CONST RVALUE mrb_preset_object_83 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 1,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_16 } }, } };
PRESET_CONST RVALUE mrb_preset_object_84 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 1,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_17 } }, } };
PRESET_CONST RVALUE mrb_preset_object_85 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 1,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_18 } }, } };
PRESET_CONST RVALUE mrb_preset_object_86 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 1,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_19 } }, } };
PRESET_CONST RVALUE mrb_preset_object_87 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_30 }, .upper = (struct RProc *)&mrb_preset_object_30.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_30.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_88 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 1,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_20 } }, } };
PRESET_CONST RVALUE mrb_preset_object_89 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_31 }, .upper = (struct RProc *)&mrb_preset_object_30.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_30.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_90 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 15,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_21 } }, } };
PRESET_CONST RVALUE mrb_preset_object_91 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 6,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_22 } }, } };
PRESET_CONST RVALUE mrb_preset_object_92 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 0,.aux = { .capa = 0 }, .ptr = NULL } }, } };
PRESET_CONST RVALUE mrb_preset_object_93 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_32 }, .upper = (struct RProc *)&mrb_preset_object_30.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_30.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_94 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_33 }, .upper = (struct RProc *)&mrb_preset_object_30.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_30.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_95 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 0,.aux = { .capa = 0 }, .ptr = NULL } }, } };
PRESET_CONST RVALUE mrb_preset_object_96 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_35 }, .upper = (struct RProc *)&mrb_preset_object_30.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_30.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_97 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 26,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_0 } }, } };
PRESET_CONST RVALUE mrb_preset_object_98 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 36,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_23 } }, } };
PRESET_CONST RVALUE mrb_preset_object_99 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 0,.aux = { .capa = 0 }, .ptr = NULL } }, } };
PRESET_CONST RVALUE mrb_preset_object_100 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_36 }, .upper = (struct RProc *)&mrb_preset_object_30.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_30.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_101 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 15,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_21 } }, } };
PRESET_CONST RVALUE mrb_preset_object_102 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 6,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_22 } }, } };
PRESET_CONST RVALUE mrb_preset_object_103 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 0,.aux = { .capa = 0 }, .ptr = NULL } }, } };
PRESET_CONST RVALUE mrb_preset_object_104 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_37 }, .upper = (struct RProc *)&mrb_preset_object_30.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_30.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_105 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 0,.aux = { .capa = 0 }, .ptr = NULL } }, } };
PRESET_CONST RVALUE mrb_preset_object_106 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_38 }, .upper = (struct RProc *)&mrb_preset_object_30.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_30.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_107 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_7 }, .upper = (struct RProc *)&mrb_preset_object_30.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_30.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_108 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_39 }, .upper = (struct RProc *)&mrb_preset_object_30.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_30.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_109 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 0,.aux = { .capa = 0 }, .ptr = NULL } }, } };
PRESET_CONST RVALUE mrb_preset_object_110 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 18,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_24 } }, } };
PRESET_CONST RVALUE mrb_preset_object_111 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 6,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_25 } }, } };
PRESET_CONST RVALUE mrb_preset_object_112 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 14,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_26 } }, } };
PRESET_CONST RVALUE mrb_preset_object_113 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 16,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_27 } }, } };
PRESET_CONST RVALUE mrb_preset_object_114 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 27,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_3 } }, } };
PRESET_CONST RVALUE mrb_preset_object_115 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 10,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_28 } }, } };
PRESET_CONST RVALUE mrb_preset_object_116 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_40 }, .upper = (struct RProc *)&mrb_preset_object_30.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_30.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_117 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 1,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_2 } }, } };
PRESET_CONST RVALUE mrb_preset_object_118 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 0,.aux = { .capa = 0 }, .ptr = NULL } }, } };
PRESET_CONST RVALUE mrb_preset_object_119 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 18,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_29 } }, } };
PRESET_CONST RVALUE mrb_preset_object_120 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_41 }, .upper = (struct RProc *)&mrb_preset_object_30.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_30.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_121 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 1,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_2 } }, } };
PRESET_CONST RVALUE mrb_preset_object_122 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 0,.aux = { .capa = 0 }, .ptr = NULL } }, } };
PRESET_CONST RVALUE mrb_preset_object_123 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 18,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_29 } }, } };
PRESET_CONST RVALUE mrb_preset_object_124 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_42 }, .upper = (struct RProc *)&mrb_preset_object_30.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_30.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_125 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 27,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_30 } }, } };
PRESET_CONST RVALUE mrb_preset_object_126 = { .klass = { .tt = MRB_TT_ICLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_127.klass, .gcnext = (struct RBasic *)&mrb_preset_object_148.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_25, .mt = (struct kh_mt *)&mrb_preset_kh_mt_21, .super = (struct RClass *)&mrb_preset_object_0.klass, } };
PRESET_CONST RVALUE mrb_preset_object_127 = { .klass = { .tt = MRB_TT_MODULE, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_6.klass, .gcnext = (struct RBasic *)&mrb_preset_object_126.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_25, .mt = (struct kh_mt *)&mrb_preset_kh_mt_21, .super = NULL, } };
PRESET_CONST RVALUE mrb_preset_object_128 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_43 }, .upper = (struct RProc *)&mrb_preset_object_127.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_127.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_129 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_44 }, .upper = (struct RProc *)&mrb_preset_object_127.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_127.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_130 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 14,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_31 } }, } };
PRESET_CONST RVALUE mrb_preset_object_131 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 6,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_32 } }, } };
PRESET_CONST RVALUE mrb_preset_object_132 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 7,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_33 } }, } };
PRESET_CONST RVALUE mrb_preset_object_133 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_45 }, .upper = (struct RProc *)&mrb_preset_object_127.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_127.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_134 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_46 }, .upper = (struct RProc *)&mrb_preset_object_127.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_127.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_135 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 14,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_31 } }, } };
PRESET_CONST RVALUE mrb_preset_object_136 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 6,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_32 } }, } };
PRESET_CONST RVALUE mrb_preset_object_137 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 7,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_33 } }, } };
PRESET_CONST RVALUE mrb_preset_object_138 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_47 }, .upper = (struct RProc *)&mrb_preset_object_127.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_127.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_139 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 14,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_31 } }, } };
PRESET_CONST RVALUE mrb_preset_object_140 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 6,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_32 } }, } };
PRESET_CONST RVALUE mrb_preset_object_141 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 7,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_33 } }, } };
PRESET_CONST RVALUE mrb_preset_object_142 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_48 }, .upper = (struct RProc *)&mrb_preset_object_127.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_127.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_143 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 14,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_31 } }, } };
PRESET_CONST RVALUE mrb_preset_object_144 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 6,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_32 } }, } };
PRESET_CONST RVALUE mrb_preset_object_145 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 7,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_33 } }, } };
PRESET_CONST RVALUE mrb_preset_object_146 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_49 }, .upper = (struct RProc *)&mrb_preset_object_147.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_147.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_147 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0xe, .c = (struct RClass *)&mrb_preset_object_148.klass, .gcnext = (struct RBasic *)&mrb_preset_object_169.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_26, .mt = (struct kh_mt *)&mrb_preset_kh_mt_23, .super = (struct RClass *)&mrb_preset_object_168.klass, } };
PRESET_CONST RVALUE mrb_preset_object_148 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_147.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_27, .mt = (struct kh_mt *)&mrb_preset_kh_mt_22, .super = (struct RClass *)&mrb_preset_object_10.klass, } };
PRESET_CONST RVALUE mrb_preset_object_149 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_50 }, .upper = (struct RProc *)&mrb_preset_object_147.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_147.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_150 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_51 }, .upper = (struct RProc *)&mrb_preset_object_147.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_147.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_151 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_52 }, .upper = (struct RProc *)&mrb_preset_object_147.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_147.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_152 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 2,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_34 } }, } };
PRESET_CONST RVALUE mrb_preset_object_153 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 1,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_34 } }, } };
PRESET_CONST RVALUE mrb_preset_object_154 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 2,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_4 } }, } };
PRESET_CONST RVALUE mrb_preset_object_155 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 1,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_35 } }, } };
PRESET_CONST RVALUE mrb_preset_object_156 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_54 }, .upper = (struct RProc *)&mrb_preset_object_147.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_147.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_157 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_55 }, .upper = (struct RProc *)&mrb_preset_object_147.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_147.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_158 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_56 }, .upper = (struct RProc *)&mrb_preset_object_147.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_147.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_159 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 5,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_36 } }, } };
PRESET_CONST RVALUE mrb_preset_object_160 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_57 }, .upper = (struct RProc *)&mrb_preset_object_147.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_147.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_161 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 33,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_37 } }, } };
PRESET_CONST RVALUE mrb_preset_object_162 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 19,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_38 } }, } };
PRESET_CONST RVALUE mrb_preset_object_163 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_58 }, .upper = (struct RProc *)&mrb_preset_object_147.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_147.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_164 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_59 }, .upper = (struct RProc *)&mrb_preset_object_147.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_147.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_165 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_60 }, .upper = (struct RProc *)&mrb_preset_object_147.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_147.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_166 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_61 }, .upper = (struct RProc *)&mrb_preset_object_147.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_147.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_167 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_62 }, .upper = (struct RProc *)&mrb_preset_object_147.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_147.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_168 = { .klass = { .tt = MRB_TT_ICLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_169.klass, .gcnext = (struct RBasic *)&mrb_preset_object_21.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_28, .mt = (struct kh_mt *)&mrb_preset_kh_mt_24, .super = (struct RClass *)&mrb_preset_object_0.klass, } };
PRESET_CONST RVALUE mrb_preset_object_169 = { .klass = { .tt = MRB_TT_MODULE, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_6.klass, .gcnext = (struct RBasic *)&mrb_preset_object_168.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_28, .mt = (struct kh_mt *)&mrb_preset_kh_mt_24, .super = NULL, } };
PRESET_CONST RVALUE mrb_preset_object_170 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_63 }, .upper = (struct RProc *)&mrb_preset_object_169.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_169.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_171 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_65 }, .upper = (struct RProc *)&mrb_preset_object_169.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_169.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_172 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 18,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_39 } }, } };
PRESET_CONST RVALUE mrb_preset_object_173 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_68 }, .upper = (struct RProc *)&mrb_preset_object_169.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_169.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_174 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_70 }, .upper = (struct RProc *)&mrb_preset_object_169.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_169.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_175 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_73 }, .upper = (struct RProc *)&mrb_preset_object_169.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_169.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_176 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_75 }, .upper = (struct RProc *)&mrb_preset_object_169.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_169.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_177 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_77 }, .upper = (struct RProc *)&mrb_preset_object_169.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_169.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_178 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_79 }, .upper = (struct RProc *)&mrb_preset_object_169.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_169.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_179 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_81 }, .upper = (struct RProc *)&mrb_preset_object_169.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_169.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_180 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_83 }, .upper = (struct RProc *)&mrb_preset_object_169.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_169.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_181 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_85 }, .upper = (struct RProc *)&mrb_preset_object_169.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_169.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_182 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_87 }, .upper = (struct RProc *)&mrb_preset_object_169.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_169.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_183 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_89 }, .upper = (struct RProc *)&mrb_preset_object_169.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_169.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_184 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_91 }, .upper = (struct RProc *)&mrb_preset_object_169.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_169.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_185 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_93 }, .upper = (struct RProc *)&mrb_preset_object_169.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_169.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_186 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_95 }, .upper = (struct RProc *)&mrb_preset_object_169.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_169.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_187 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_98 }, .upper = (struct RProc *)&mrb_preset_object_22.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_22.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_188 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0xc80, .c = NULL, .gcnext = NULL, .body = { .func = (mrb_func_t)attr_writer }, .upper = NULL, .e = { .env = (struct REnv *)&mrb_preset_object_189.env }, } };
PRESET_DATA RVALUE mrb_preset_object_189 = { .env = { .tt = MRB_TT_ENV, .color = 4, .flags = 0x100801, .c = NULL, .gcnext = NULL, .stack = (mrb_value *)&mrb_preset_env_stacks_189, .cxt = (struct mrb_context *)&mrb_preset_context_0, .mid = (mrb_sym)41, } };
PRESET_CONST RVALUE mrb_preset_object_190 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_99 }, .upper = (struct RProc *)&mrb_preset_object_19.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_19.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_191 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0xc80, .c = NULL, .gcnext = NULL, .body = { .func = (mrb_func_t)attr_reader }, .upper = NULL, .e = { .env = (struct REnv *)&mrb_preset_object_192.env }, } };
PRESET_DATA RVALUE mrb_preset_object_192 = { .env = { .tt = MRB_TT_ENV, .color = 4, .flags = 0x100801, .c = NULL, .gcnext = NULL, .stack = (mrb_value *)&mrb_preset_env_stacks_192, .cxt = (struct mrb_context *)&mrb_preset_context_0, .mid = (mrb_sym)40, } };
PRESET_CONST RVALUE mrb_preset_object_193 = { .klass = { .tt = MRB_TT_MODULE, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_194.klass, .gcnext = (struct RBasic *)&mrb_preset_object_197.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_29, .mt = (struct kh_mt *)&mrb_preset_kh_mt_29, .super = NULL, } };
PRESET_CONST RVALUE mrb_preset_object_194 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_195.klass, .gcnext = (struct RBasic *)&mrb_preset_object_193.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_30, .mt = (struct kh_mt *)&mrb_preset_kh_mt_28, .super = (struct RClass *)&mrb_preset_object_6.klass, } };
PRESET_CONST RVALUE mrb_preset_object_195 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_194.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_31, .mt = (struct kh_mt *)&mrb_preset_kh_mt_27, .super = (struct RClass *)&mrb_preset_object_5.klass, } };
PRESET_CONST RVALUE mrb_preset_object_196 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0x12, .c = (struct RClass *)&mrb_preset_object_197.klass, .gcnext = (struct RBasic *)&mrb_preset_object_199.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_32, .mt = (struct kh_mt *)&mrb_preset_kh_mt_31, .super = (struct RClass *)&mrb_preset_object_18.klass, } };
PRESET_CONST RVALUE mrb_preset_object_197 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_196.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_33, .mt = (struct kh_mt *)&mrb_preset_kh_mt_30, .super = (struct RClass *)&mrb_preset_object_17.klass, } };
PRESET_CONST RVALUE mrb_preset_object_198 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0x12, .c = (struct RClass *)&mrb_preset_object_199.klass, .gcnext = (struct RBasic *)&mrb_preset_object_205.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_34, .mt = (struct kh_mt *)&mrb_preset_kh_mt_33, .super = (struct RClass *)&mrb_preset_object_14.klass, } };
PRESET_CONST RVALUE mrb_preset_object_199 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_198.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_35, .mt = (struct kh_mt *)&mrb_preset_kh_mt_32, .super = (struct RClass *)&mrb_preset_object_13.klass, } };
PRESET_CONST RVALUE mrb_preset_object_200 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0xc80, .c = NULL, .gcnext = NULL, .body = { .func = (mrb_func_t)attr_reader }, .upper = NULL, .e = { .env = (struct REnv *)&mrb_preset_object_201.env }, } };
PRESET_DATA RVALUE mrb_preset_object_201 = { .env = { .tt = MRB_TT_ENV, .color = 4, .flags = 0x100801, .c = NULL, .gcnext = NULL, .stack = (mrb_value *)&mrb_preset_env_stacks_201, .cxt = (struct mrb_context *)&mrb_preset_context_0, .mid = (mrb_sym)40, } };
PRESET_CONST RVALUE mrb_preset_object_202 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0xc80, .c = NULL, .gcnext = NULL, .body = { .func = (mrb_func_t)attr_writer }, .upper = NULL, .e = { .env = (struct REnv *)&mrb_preset_object_203.env }, } };
PRESET_DATA RVALUE mrb_preset_object_203 = { .env = { .tt = MRB_TT_ENV, .color = 4, .flags = 0x100801, .c = NULL, .gcnext = NULL, .stack = (mrb_value *)&mrb_preset_env_stacks_203, .cxt = (struct mrb_context *)&mrb_preset_context_0, .mid = (mrb_sym)41, } };
PRESET_CONST RVALUE mrb_preset_object_204 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0x12, .c = (struct RClass *)&mrb_preset_object_205.klass, .gcnext = (struct RBasic *)&mrb_preset_object_207.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_36, .mt = (struct kh_mt *)&mrb_preset_kh_mt_35, .super = (struct RClass *)&mrb_preset_object_15.klass, } };
PRESET_CONST RVALUE mrb_preset_object_205 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_204.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_37, .mt = (struct kh_mt *)&mrb_preset_kh_mt_34, .super = (struct RClass *)&mrb_preset_object_16.klass, } };
PRESET_CONST RVALUE mrb_preset_object_206 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0x12, .c = (struct RClass *)&mrb_preset_object_207.klass, .gcnext = (struct RBasic *)&mrb_preset_object_209.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_38, .mt = (struct kh_mt *)&mrb_preset_kh_mt_37, .super = (struct RClass *)&mrb_preset_object_196.klass, } };
PRESET_CONST RVALUE mrb_preset_object_207 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_206.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_39, .mt = (struct kh_mt *)&mrb_preset_kh_mt_36, .super = (struct RClass *)&mrb_preset_object_197.klass, } };
PRESET_CONST RVALUE mrb_preset_object_208 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0xd, .c = (struct RClass *)&mrb_preset_object_209.klass, .gcnext = (struct RBasic *)&mrb_preset_object_212.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_40, .mt = (struct kh_mt *)&mrb_preset_kh_mt_39, .super = (struct RClass *)&mrb_preset_object_0.klass, } };
PRESET_CONST RVALUE mrb_preset_object_209 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_208.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_41, .mt = (struct kh_mt *)&mrb_preset_kh_mt_38, .super = (struct RClass *)&mrb_preset_object_10.klass, } };
PRESET_CONST RVALUE mrb_preset_object_210 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x800, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_100 }, .upper = NULL, .e = { .target_class = (struct RClass *)&mrb_preset_object_208.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_211 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0x12, .c = (struct RClass *)&mrb_preset_object_212.klass, .gcnext = (struct RBasic *)&mrb_preset_object_214.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_42, .mt = (struct kh_mt *)&mrb_preset_kh_mt_41, .super = (struct RClass *)&mrb_preset_object_204.klass, } };
PRESET_CONST RVALUE mrb_preset_object_212 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_211.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_43, .mt = (struct kh_mt *)&mrb_preset_kh_mt_40, .super = (struct RClass *)&mrb_preset_object_205.klass, } };
PRESET_CONST RVALUE mrb_preset_object_213 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0xf, .c = (struct RClass *)&mrb_preset_object_214.klass, .gcnext = (struct RBasic *)&mrb_preset_object_239.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_44, .mt = (struct kh_mt *)&mrb_preset_kh_mt_43, .super = (struct RClass *)&mrb_preset_object_239.klass, } };
PRESET_CONST RVALUE mrb_preset_object_214 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_213.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_45, .mt = (struct kh_mt *)&mrb_preset_kh_mt_42, .super = (struct RClass *)&mrb_preset_object_10.klass, } };
PRESET_CONST RVALUE mrb_preset_object_215 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_101 }, .upper = (struct RProc *)&mrb_preset_object_213.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_213.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_216 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 32,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_40 } }, } };
PRESET_CONST RVALUE mrb_preset_object_217 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_103 }, .upper = (struct RProc *)&mrb_preset_object_213.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_213.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_218 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 5,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_41 } }, } };
PRESET_CONST RVALUE mrb_preset_object_219 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_104 }, .upper = (struct RProc *)&mrb_preset_object_213.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_213.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_220 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 2,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_42 } }, } };
PRESET_CONST RVALUE mrb_preset_object_221 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 1,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_41 } }, } };
PRESET_CONST RVALUE mrb_preset_object_222 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 2,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_4 } }, } };
PRESET_CONST RVALUE mrb_preset_object_223 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 1,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_43 } }, } };
PRESET_CONST RVALUE mrb_preset_object_224 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 2,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_44 } }, } };
PRESET_CONST RVALUE mrb_preset_object_225 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_106 }, .upper = (struct RProc *)&mrb_preset_object_213.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_213.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_226 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_107 }, .upper = (struct RProc *)&mrb_preset_object_213.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_213.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_227 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_109 }, .upper = (struct RProc *)&mrb_preset_object_213.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_213.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_228 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 32,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_40 } }, } };
PRESET_CONST RVALUE mrb_preset_object_229 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_113 }, .upper = (struct RProc *)&mrb_preset_object_213.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_213.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_230 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_115 }, .upper = (struct RProc *)&mrb_preset_object_213.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_213.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_231 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_118 }, .upper = (struct RProc *)&mrb_preset_object_213.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_213.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_232 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_121 }, .upper = (struct RProc *)&mrb_preset_object_213.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_213.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_233 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_123 }, .upper = (struct RProc *)&mrb_preset_object_213.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_213.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_234 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_124 }, .upper = (struct RProc *)&mrb_preset_object_213.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_213.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_235 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_126 }, .upper = (struct RProc *)&mrb_preset_object_213.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_213.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_236 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_128 }, .upper = (struct RProc *)&mrb_preset_object_213.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_213.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_237 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_130 }, .upper = (struct RProc *)&mrb_preset_object_213.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_213.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_238 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_132 }, .upper = (struct RProc *)&mrb_preset_object_213.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_213.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_239 = { .klass = { .tt = MRB_TT_ICLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_169.klass, .gcnext = (struct RBasic *)&mrb_preset_object_240.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_28, .mt = (struct kh_mt *)&mrb_preset_kh_mt_24, .super = (struct RClass *)&mrb_preset_object_0.klass, } };
PRESET_CONST RVALUE mrb_preset_object_240 = { .klass = { .tt = MRB_TT_MODULE, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_6.klass, .gcnext = (struct RBasic *)&mrb_preset_object_254.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_46, .mt = (struct kh_mt *)&mrb_preset_kh_mt_44, .super = NULL, } };
PRESET_CONST RVALUE mrb_preset_object_241 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_134 }, .upper = (struct RProc *)&mrb_preset_object_240.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_240.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_242 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_135 }, .upper = (struct RProc *)&mrb_preset_object_240.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_240.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_243 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_136 }, .upper = (struct RProc *)&mrb_preset_object_240.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_240.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_244 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_137 }, .upper = (struct RProc *)&mrb_preset_object_240.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_240.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_245 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_138 }, .upper = (struct RProc *)&mrb_preset_object_240.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_240.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_246 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_139 }, .upper = (struct RProc *)&mrb_preset_object_240.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_240.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_247 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_140 }, .upper = (struct RProc *)&mrb_preset_object_240.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_240.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_248 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_141 }, .upper = (struct RProc *)&mrb_preset_object_240.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_240.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_249 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 15,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_45 } }, } };
PRESET_CONST RVALUE mrb_preset_object_250 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 5,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_46 } }, } };
PRESET_CONST RVALUE mrb_preset_object_251 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_142 }, .upper = (struct RProc *)&mrb_preset_object_240.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_240.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_252 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_143 }, .upper = (struct RProc *)&mrb_preset_object_240.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_240.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_253 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0x11, .c = (struct RClass *)&mrb_preset_object_254.klass, .gcnext = (struct RBasic *)&mrb_preset_object_258.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_47, .mt = (struct kh_mt *)&mrb_preset_kh_mt_46, .super = (struct RClass *)&mrb_preset_object_258.klass, } };
PRESET_CONST RVALUE mrb_preset_object_254 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_253.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_48, .mt = (struct kh_mt *)&mrb_preset_kh_mt_45, .super = (struct RClass *)&mrb_preset_object_10.klass, } };
PRESET_CONST RVALUE mrb_preset_object_255 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_144 }, .upper = (struct RProc *)&mrb_preset_object_253.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_253.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_256 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_145 }, .upper = (struct RProc *)&mrb_preset_object_253.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_253.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_257 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 13,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_47 } }, } };
PRESET_CONST RVALUE mrb_preset_object_258 = { .klass = { .tt = MRB_TT_ICLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_169.klass, .gcnext = (struct RBasic *)&mrb_preset_object_260.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_28, .mt = (struct kh_mt *)&mrb_preset_kh_mt_24, .super = (struct RClass *)&mrb_preset_object_0.klass, } };
PRESET_CONST RVALUE mrb_preset_object_259 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0x6, .c = (struct RClass *)&mrb_preset_object_260.klass, .gcnext = (struct RBasic *)&mrb_preset_object_267.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_49, .mt = (struct kh_mt *)&mrb_preset_kh_mt_50, .super = (struct RClass *)&mrb_preset_object_267.klass, } };
PRESET_CONST RVALUE mrb_preset_object_260 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_262.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_50, .mt = (struct kh_mt *)&mrb_preset_kh_mt_47, .super = (struct RClass *)&mrb_preset_object_261.klass, } };
PRESET_CONST RVALUE mrb_preset_object_261 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_259.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_51, .mt = (struct kh_mt *)&mrb_preset_kh_mt_49, .super = (struct RClass *)&mrb_preset_object_10.klass, } };
PRESET_CONST RVALUE mrb_preset_object_262 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_261.klass, .gcnext = (struct RBasic *)&mrb_preset_object_266.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_52, .mt = (struct kh_mt *)&mrb_preset_kh_mt_48, .super = (struct RClass *)&mrb_preset_object_266.klass, } };
PRESET_CONST RVALUE mrb_preset_object_263 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_146 }, .upper = (struct RProc *)&mrb_preset_object_262.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_262.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_264 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_147 }, .upper = (struct RProc *)&mrb_preset_object_262.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_262.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_265 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_148 }, .upper = (struct RProc *)&mrb_preset_object_262.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_262.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_266 = { .klass = { .tt = MRB_TT_ICLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_127.klass, .gcnext = (struct RBasic *)&mrb_preset_object_261.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_25, .mt = (struct kh_mt *)&mrb_preset_kh_mt_21, .super = (struct RClass *)&mrb_preset_object_0.klass, } };
PRESET_CONST RVALUE mrb_preset_object_267 = { .klass = { .tt = MRB_TT_ICLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_240.klass, .gcnext = (struct RBasic *)&mrb_preset_object_272.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_46, .mt = (struct kh_mt *)&mrb_preset_kh_mt_44, .super = (struct RClass *)&mrb_preset_object_262.klass, } };
PRESET_CONST RVALUE mrb_preset_object_268 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 9,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_48 } }, } };
PRESET_CONST RVALUE mrb_preset_object_269 = { .klass = { .tt = MRB_TT_MODULE, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_273.klass, .gcnext = (struct RBasic *)&mrb_preset_object_277.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_53, .mt = (struct kh_mt *)&mrb_preset_kh_mt_55, .super = NULL, } };
PRESET_CONST RVALUE mrb_preset_object_270 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0x12, .c = (struct RClass *)&mrb_preset_object_272.klass, .gcnext = (struct RBasic *)&mrb_preset_object_274.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_54, .mt = (struct kh_mt *)&mrb_preset_kh_mt_52, .super = (struct RClass *)&mrb_preset_object_15.klass, } };
PRESET_CONST RVALUE mrb_preset_object_271 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 17,.aux = { .capa = 22 }, .ptr = (char *)&mrb_preset_strings_49 } }, } };
PRESET_CONST RVALUE mrb_preset_object_272 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_270.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_55, .mt = (struct kh_mt *)&mrb_preset_kh_mt_51, .super = (struct RClass *)&mrb_preset_object_16.klass, } };
PRESET_CONST RVALUE mrb_preset_object_273 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_274.klass, .gcnext = (struct RBasic *)&mrb_preset_object_269.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_56, .mt = (struct kh_mt *)&mrb_preset_kh_mt_54, .super = (struct RClass *)&mrb_preset_object_6.klass, } };
PRESET_CONST RVALUE mrb_preset_object_274 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_273.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_57, .mt = (struct kh_mt *)&mrb_preset_kh_mt_53, .super = (struct RClass *)&mrb_preset_object_5.klass, } };
PRESET_CONST RVALUE mrb_preset_object_275 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 5,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_50 } }, } };
PRESET_CONST RVALUE mrb_preset_object_276 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0x2, .c = (struct RClass *)&mrb_preset_object_277.klass, .gcnext = (struct RBasic *)&mrb_preset_object_279.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_58, .mt = (struct kh_mt *)&mrb_preset_kh_mt_57, .super = (struct RClass *)&mrb_preset_object_0.klass, } };
PRESET_CONST RVALUE mrb_preset_object_277 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_276.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_59, .mt = (struct kh_mt *)&mrb_preset_kh_mt_56, .super = (struct RClass *)&mrb_preset_object_10.klass, } };
PRESET_CONST RVALUE mrb_preset_object_278 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0x2, .c = (struct RClass *)&mrb_preset_object_279.klass, .gcnext = (struct RBasic *)&mrb_preset_object_282.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_60, .mt = (struct kh_mt *)&mrb_preset_kh_mt_59, .super = (struct RClass *)&mrb_preset_object_0.klass, } };
PRESET_CONST RVALUE mrb_preset_object_279 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_278.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_61, .mt = (struct kh_mt *)&mrb_preset_kh_mt_58, .super = (struct RClass *)&mrb_preset_object_10.klass, } };
PRESET_CONST RVALUE mrb_preset_object_280 = { .klass = { .tt = MRB_TT_MODULE, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_281.klass, .gcnext = (struct RBasic *)&mrb_preset_object_292.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_62, .mt = (struct kh_mt *)&mrb_preset_kh_mt_62, .super = NULL, } };
PRESET_CONST RVALUE mrb_preset_object_281 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_282.klass, .gcnext = (struct RBasic *)&mrb_preset_object_280.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_63, .mt = (struct kh_mt *)&mrb_preset_kh_mt_61, .super = (struct RClass *)&mrb_preset_object_6.klass, } };
PRESET_CONST RVALUE mrb_preset_object_282 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_281.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_64, .mt = (struct kh_mt *)&mrb_preset_kh_mt_60, .super = (struct RClass *)&mrb_preset_object_5.klass, } };
PRESET_CONST RVALUE mrb_preset_object_283 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_149 }, .upper = (struct RProc *)&mrb_preset_object_280.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_280.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_284 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_150 }, .upper = (struct RProc *)&mrb_preset_object_280.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_280.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_285 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_151 }, .upper = (struct RProc *)&mrb_preset_object_280.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_280.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_286 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 29,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_51 } }, } };
PRESET_CONST RVALUE mrb_preset_object_287 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_152 }, .upper = (struct RProc *)&mrb_preset_object_280.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_280.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_288 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4000c, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 26,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_52 } }, } };
PRESET_CONST RVALUE mrb_preset_object_289 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_153 }, .upper = (struct RProc *)&mrb_preset_object_280.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_280.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_290 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 3,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_53 } }, } };
PRESET_CONST RVALUE mrb_preset_object_291 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0x2, .c = (struct RClass *)&mrb_preset_object_292.klass, .gcnext = (struct RBasic *)&mrb_preset_object_295.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_65, .mt = (struct kh_mt *)&mrb_preset_kh_mt_64, .super = (struct RClass *)&mrb_preset_object_0.klass, } };
PRESET_CONST RVALUE mrb_preset_object_292 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_291.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_66, .mt = (struct kh_mt *)&mrb_preset_kh_mt_63, .super = (struct RClass *)&mrb_preset_object_10.klass, } };
PRESET_CONST RVALUE mrb_preset_object_293 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 5,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_54 } }, } };
PRESET_CONST RVALUE mrb_preset_object_294 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0x3, .c = (struct RClass *)&mrb_preset_object_295.klass, .gcnext = (struct RBasic *)&mrb_preset_object_302.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_67, .mt = (struct kh_mt *)&mrb_preset_kh_mt_68, .super = (struct RClass *)&mrb_preset_object_297.klass, } };
PRESET_CONST RVALUE mrb_preset_object_295 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_297.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_68, .mt = (struct kh_mt *)&mrb_preset_kh_mt_65, .super = (struct RClass *)&mrb_preset_object_296.klass, } };
PRESET_CONST RVALUE mrb_preset_object_296 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_294.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_69, .mt = (struct kh_mt *)&mrb_preset_kh_mt_67, .super = (struct RClass *)&mrb_preset_object_261.klass, } };
PRESET_CONST RVALUE mrb_preset_object_297 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0x3, .c = (struct RClass *)&mrb_preset_object_296.klass, .gcnext = (struct RBasic *)&mrb_preset_object_300.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_70, .mt = (struct kh_mt *)&mrb_preset_kh_mt_66, .super = (struct RClass *)&mrb_preset_object_300.klass, } };
PRESET_CONST RVALUE mrb_preset_object_298 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_154 }, .upper = (struct RProc *)&mrb_preset_object_297.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_297.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_299 = { .proc = { .tt = MRB_TT_PROC, .color = 4, .flags = 0x900, .c = NULL, .gcnext = NULL, .body = { .irep = (mrb_irep *)&mrb_preset_irep_155 }, .upper = (struct RProc *)&mrb_preset_object_297.proc, .e = { .target_class = (struct RClass *)&mrb_preset_object_297.klass }, } };
PRESET_CONST RVALUE mrb_preset_object_300 = { .klass = { .tt = MRB_TT_ICLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_240.klass, .gcnext = (struct RBasic *)&mrb_preset_object_296.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_46, .mt = (struct kh_mt *)&mrb_preset_kh_mt_44, .super = (struct RClass *)&mrb_preset_object_262.klass, } };
PRESET_CONST RVALUE mrb_preset_object_301 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0x16, .c = (struct RClass *)&mrb_preset_object_302.klass, .gcnext = (struct RBasic *)&mrb_preset_object_304.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_71, .mt = (struct kh_mt *)&mrb_preset_kh_mt_70, .super = (struct RClass *)&mrb_preset_object_0.klass, } };
PRESET_CONST RVALUE mrb_preset_object_302 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_301.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_72, .mt = (struct kh_mt *)&mrb_preset_kh_mt_69, .super = (struct RClass *)&mrb_preset_object_10.klass, } };
PRESET_CONST RVALUE mrb_preset_object_303 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0x12, .c = (struct RClass *)&mrb_preset_object_304.klass, .gcnext = (struct RBasic *)&mrb_preset_object_308.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_73, .mt = (struct kh_mt *)&mrb_preset_kh_mt_74, .super = (struct RClass *)&mrb_preset_object_306.klass, } };
PRESET_CONST RVALUE mrb_preset_object_304 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_306.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_74, .mt = (struct kh_mt *)&mrb_preset_kh_mt_71, .super = (struct RClass *)&mrb_preset_object_305.klass, } };
PRESET_CONST RVALUE mrb_preset_object_305 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_303.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_75, .mt = (struct kh_mt *)&mrb_preset_kh_mt_73, .super = (struct RClass *)&mrb_preset_object_16.klass, } };
PRESET_CONST RVALUE mrb_preset_object_306 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0x12, .c = (struct RClass *)&mrb_preset_object_305.klass, .gcnext = (struct RBasic *)&mrb_preset_object_305.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_76, .mt = (struct kh_mt *)&mrb_preset_kh_mt_72, .super = (struct RClass *)&mrb_preset_object_15.klass, } };
PRESET_CONST RVALUE mrb_preset_object_307 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0x4, .c = (struct RClass *)&mrb_preset_object_308.klass, .gcnext = (struct RBasic *)&mrb_preset_object_310.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_77, .mt = (struct kh_mt *)&mrb_preset_kh_mt_76, .super = (struct RClass *)&mrb_preset_object_0.klass, } };
PRESET_CONST RVALUE mrb_preset_object_308 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_307.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_78, .mt = (struct kh_mt *)&mrb_preset_kh_mt_75, .super = (struct RClass *)&mrb_preset_object_10.klass, } };
PRESET_CONST RVALUE mrb_preset_object_309 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0x12, .c = (struct RClass *)&mrb_preset_object_310.klass, .gcnext = (struct RBasic *)&mrb_preset_object_312.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_79, .mt = (struct kh_mt *)&mrb_preset_kh_mt_78, .super = (struct RClass *)&mrb_preset_object_15.klass, } };
PRESET_CONST RVALUE mrb_preset_object_310 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_309.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_80, .mt = (struct kh_mt *)&mrb_preset_kh_mt_77, .super = (struct RClass *)&mrb_preset_object_16.klass, } };
PRESET_CONST RVALUE mrb_preset_object_311 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0x12, .c = (struct RClass *)&mrb_preset_object_312.klass, .gcnext = (struct RBasic *)&mrb_preset_object_314.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_81, .mt = (struct kh_mt *)&mrb_preset_kh_mt_80, .super = (struct RClass *)&mrb_preset_object_15.klass, } };
PRESET_CONST RVALUE mrb_preset_object_312 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_311.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_82, .mt = (struct kh_mt *)&mrb_preset_kh_mt_79, .super = (struct RClass *)&mrb_preset_object_16.klass, } };
PRESET_CONST RVALUE mrb_preset_object_313 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0x12, .c = (struct RClass *)&mrb_preset_object_314.klass, .gcnext = (struct RBasic *)&mrb_preset_object_317.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_83, .mt = (struct kh_mt *)&mrb_preset_kh_mt_82, .super = (struct RClass *)&mrb_preset_object_18.klass, } };
PRESET_CONST RVALUE mrb_preset_object_314 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_313.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_84, .mt = (struct kh_mt *)&mrb_preset_kh_mt_81, .super = (struct RClass *)&mrb_preset_object_17.klass, } };
PRESET_CONST RVALUE mrb_preset_object_315 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 24,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_55 } }, } };
PRESET_CONST RVALUE mrb_preset_object_316 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0x12, .c = (struct RClass *)&mrb_preset_object_317.klass, .gcnext = (struct RBasic *)&mrb_preset_object_320.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_85, .mt = (struct kh_mt *)&mrb_preset_kh_mt_84, .super = (struct RClass *)&mrb_preset_object_196.klass, } };
PRESET_CONST RVALUE mrb_preset_object_317 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_316.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_86, .mt = (struct kh_mt *)&mrb_preset_kh_mt_83, .super = (struct RClass *)&mrb_preset_object_197.klass, } };
PRESET_CONST RVALUE mrb_preset_object_318 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 48,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_56 } }, } };
PRESET_CONST RVALUE mrb_preset_object_319 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0x12, .c = (struct RClass *)&mrb_preset_object_320.klass, .gcnext = (struct RBasic *)&mrb_preset_object_322.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_87, .mt = (struct kh_mt *)&mrb_preset_kh_mt_86, .super = (struct RClass *)&mrb_preset_object_15.klass, } };
PRESET_CONST RVALUE mrb_preset_object_320 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_319.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_88, .mt = (struct kh_mt *)&mrb_preset_kh_mt_85, .super = (struct RClass *)&mrb_preset_object_16.klass, } };
PRESET_CONST RVALUE mrb_preset_object_321 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0x12, .c = (struct RClass *)&mrb_preset_object_322.klass, .gcnext = (struct RBasic *)&mrb_preset_object_324.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_89, .mt = (struct kh_mt *)&mrb_preset_kh_mt_88, .super = (struct RClass *)&mrb_preset_object_18.klass, } };
PRESET_CONST RVALUE mrb_preset_object_322 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_321.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_90, .mt = (struct kh_mt *)&mrb_preset_kh_mt_87, .super = (struct RClass *)&mrb_preset_object_17.klass, } };
PRESET_CONST RVALUE mrb_preset_object_323 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0x12, .c = (struct RClass *)&mrb_preset_object_324.klass, .gcnext = (struct RBasic *)&mrb_preset_object_326.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_91, .mt = (struct kh_mt *)&mrb_preset_kh_mt_90, .super = (struct RClass *)&mrb_preset_object_196.klass, } };
PRESET_CONST RVALUE mrb_preset_object_324 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_323.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_92, .mt = (struct kh_mt *)&mrb_preset_kh_mt_89, .super = (struct RClass *)&mrb_preset_object_197.klass, } };
PRESET_CONST RVALUE mrb_preset_object_325 = { .klass = { .tt = MRB_TT_CLASS, .color = 4, .flags = 0x12, .c = (struct RClass *)&mrb_preset_object_326.klass, .gcnext = NULL, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_93, .mt = (struct kh_mt *)&mrb_preset_kh_mt_92, .super = (struct RClass *)&mrb_preset_object_15.klass, } };
PRESET_CONST RVALUE mrb_preset_object_326 = { .klass = { .tt = MRB_TT_SCLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_3.klass, .gcnext = (struct RBasic *)&mrb_preset_object_325.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_94, .mt = (struct kh_mt *)&mrb_preset_kh_mt_91, .super = (struct RClass *)&mrb_preset_object_16.klass, } };
PRESET_CONST RVALUE mrb_preset_object_327 = { .klass = { .tt = MRB_TT_ICLASS, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_280.klass, .gcnext = (struct RBasic *)&mrb_preset_object_328.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_62, .mt = (struct kh_mt *)&mrb_preset_kh_mt_62, .super = (struct RClass *)&mrb_preset_object_12.klass, } };
PRESET_CONST RVALUE mrb_preset_object_328 = { .exc = { .tt = MRB_TT_EXCEPTION, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_321.klass, .gcnext = (struct RBasic *)&mrb_preset_object_330.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_95, } };
PRESET_CONST RVALUE mrb_preset_object_329 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 13,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_57 } }, } };
PRESET_CONST RVALUE mrb_preset_object_330 = { .exc = { .tt = MRB_TT_EXCEPTION, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_313.klass, .gcnext = (struct RBasic *)&mrb_preset_object_332.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_96, } };
PRESET_CONST RVALUE mrb_preset_object_331 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 20,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_58 } }, } };
PRESET_CONST RVALUE mrb_preset_object_332 = { .exc = { .tt = MRB_TT_EXCEPTION, .color = 4, .flags = 0x0, .c = (struct RClass *)&mrb_preset_object_321.klass, .gcnext = (struct RBasic *)&mrb_preset_object_4.basic, .iv = (struct iv_tbl *)&mrb_preset_iv_tbl_97, } };
PRESET_CONST RVALUE mrb_preset_object_333 = { .string = { .tt = MRB_TT_STRING, .color = 4, .flags = 0x4, .c = (struct RClass *)&mrb_preset_object_30.klass, .gcnext = NULL, .as = { .heap = { .len = 20,.aux = { .capa = 0 }, .ptr = (char *)&mrb_preset_strings_59 } }, } };

PRESET_DATA struct mrb_state mrb_preset_state = {
	.jmp = NULL,
	.flags = 0,
	.allocf = NULL,
	.allocf_ud = NULL,
	.c = (struct mrb_context *)&mrb_preset_context_0,
	.root_c = (struct mrb_context *)&mrb_preset_context_0,
	.globals = NULL,
	.exc = NULL,
	.top_self = (struct RObject *)&mrb_preset_object_25.object,
	.object_class = (struct RClass *)&mrb_preset_object_0.klass,
	.class_class = (struct RClass *)&mrb_preset_object_3.klass,
	.module_class = (struct RClass *)&mrb_preset_object_6.klass,
	.proc_class = (struct RClass *)&mrb_preset_object_208.klass,
	.string_class = (struct RClass *)&mrb_preset_object_30.klass,
	.array_class = (struct RClass *)&mrb_preset_object_147.klass,
	.hash_class = (struct RClass *)&mrb_preset_object_213.klass,
	.range_class = (struct RClass *)&mrb_preset_object_253.klass,
#ifndef MRB_WITHOUT_FLOAT
	.float_class = (struct RClass *)&mrb_preset_object_259.klass,
#endif
	.fixnum_class = (struct RClass *)&mrb_preset_object_294.klass,
	.true_class = (struct RClass *)&mrb_preset_object_276.klass,
	.false_class = (struct RClass *)&mrb_preset_object_278.klass,
	.nil_class = (struct RClass *)&mrb_preset_object_291.klass,
	.symbol_class = (struct RClass *)&mrb_preset_object_307.klass,
	.kernel_module = (struct RClass *)&mrb_preset_object_280.klass,
	.mems = NULL,
	.gc = { 0 },
#ifdef MRB_METHOD_CACHE
	.cache = { 0 },
#endif
	.symidx = (sizeof(mrb_preset_symbols) / sizeof(mrb_preset_symbols[0])),
	.name2sym = NULL,
	.symtbl = NULL,
	.symcapa = 0,
#ifdef MRB_ENABLE_DEBUG_HOOK
	.code_fetch_hook = NULL,
	.debug_op_hook = NULL,
#endif
#ifdef MRB_BYTECODE_DECODE_OPTION
	.bytecode_decoder = NULL,
#endif
	.eException_class = (struct RClass *)&mrb_preset_object_18.klass,
	.eStandardError_class = (struct RClass *)&mrb_preset_object_15.klass,
	.nomem_err = (struct RObject *)&mrb_preset_object_328.object,
	.stack_err = (struct RObject *)&mrb_preset_object_330.object,
#ifdef MRB_GC_FIXED_ARENA
	.arena_err = (struct RObject *)&mrb_preset_object_332.object,
#endif
	.ud = NULL,
	.atexit_stack = NULL,
	.atexit_stack_len = 0
};

extern "C" void mrb_gc_init(mrb_state*, mrb_gc*);
extern "C"  void mrb_init_symtbl(mrb_state*);
extern "C" void mrb_final_mrbgems(mrb_state*);
extern "C" void GENERATED_TMP_mrb_mruby_ecnl_gem_init(mrb_state*);
extern "C" void GENERATED_TMP_mrb_mruby_others_gem_init(mrb_state*);
extern "C"  void sym_validate_len(mrb_state *mrb, size_t len);

extern "C" mrb_state* mrb_init(mrb_allocf f, void *ud)
{
	mrb_state *mrb = &mrb_preset_state;
	size_t len = (size_t)&mrb_preset_data_end - (size_t)&mrb_preset_data_start;

	memcpy(&mrb_preset_data_start, (void *)((intptr_t)&mrb_preset_data_start - (intptr_t)&data + (intptr_t)&mdata), len);

	mrb->allocf = f;
	mrb->ud = ud;
	mrb_gc_init(mrb, &mrb->gc);

	//mrb_init_core(mrb);
	mrb_init_symtbl(mrb);
	mrb_gc_arena_restore(mrb, 0);

	GENERATED_TMP_mrb_mruby_ecnl_gem_init(mrb);
	GENERATED_TMP_mrb_mruby_others_gem_init(mrb);
	mrb_state_atexit(mrb, mrb_final_mrbgems);
	mrb_gc_arena_restore(mrb, 0);

	return mrb;
}

static inline khint_t
sym_hash_func(mrb_state *mrb, const char *name, size_t len)
{
	khint_t h;
	size_t i;
	const char *p;
	h = 0;
	p = name;

	for (i = 0; i < len; i++) {
		h = (h << 5) - h + *p++;
	}
	return h;
}

extern "C" khint_t
kh_get_n2sp(mrb_state *mrb, const kh_n2sp_t *h, const char *name, size_t len)
{
	khint_t k = sym_hash_func(mrb, name, len) & khash_mask(h), step = 0, a;
	(void)mrb;
	while (!__ac_isempty(h->ed_flags, k)) {
		if (!__ac_isdel(h->ed_flags, k)) {
			a = h->keys[k] - 1;
			if ((strlen(mrb_preset_symbols[a]) == len)
				&& (memcmp(mrb_preset_symbols[a], name, len) == 0)) return k;
		}
		k = (k+(++step)) & khash_mask(h);
	}
	return kh_end(h);
}

extern "C" mrb_sym mrb_preset_sym_intern(mrb_state *mrb, const char *name, size_t len, mrb_bool lit)
{
	const kh_n2sp_t *h = &n2s_tbl;
	khiter_t k;

	sym_validate_len(mrb, len);
	k = kh_get_n2sp(mrb, h, name, len);
	if (k != kh_end(h))
		return kh_key(h, k);

	return 0;
}

extern "C" const char *mrb_preset_sym2name(mrb_sym sym, mrb_int *lenp)
{
	if (lenp) *lenp = strlen(mrb_preset_symbols[sym - 1]);
	return mrb_preset_symbols[sym - 1];
}

extern "C" int mrb_is_preset_const(mrb_state *mrb, void *p)
{
	if ((p >= &mrb_preset_const_start) && (p < &mrb_preset_const_end))
		return 1;
	return 0;
}

extern "C" int mrb_is_preset_data(mrb_state *mrb, void *p)
{
	if ((p >= &mrb_preset_data_start) && (p < &mrb_preset_data_end))
		return 1;
	return 0;
}
#endif
