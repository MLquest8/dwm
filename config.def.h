/*             See LICENSE file for copyright and license details.            */
/*====================================DWM=====================================*/
/*  DWM appearance settings                                                   */
static const int topbar             = 1; /* 0 means bottom bar                */
static const int showbar            = 1; /* 0 means no bar                    */
static const int barheight          = 26;/* Specific bar height (0 for def)   */
static const int showextrabar       = 1; /* 0 means no extra bar              */
static const int extrabarheight     = 16;/* Specific bar height (0 for def)   */
static const int viewontag          = 1; /* 1 Switch view on tag switch       */
static const int startontag         = 1; /* 0 means no tag is active on start */
static const int hidevactags        = 0; /* 1 means hide vacant tags          */
static const int warponfocus        = 1; /* 1 Warp pointer to focused client  */
static const int swallowfloating    = 0; /* 1 swallow all floating windows    */
static const int gapsforone         = 0; /* Gaps for only one window open     */
static const int gapsformonocle     = 0; /* Gaps for only one window open     */
static const int showsystray        = 1; /* 0 means no systray                */
static const int stfallbackmon      = 1; /* 1 means first monitor, 0 last     */
static const unsigned int stmonitor = 0; /* 0 means selected monitor          */
static const unsigned int stspacing = 2; /* systray spacing                   */
static const unsigned int igappx    = 0; /* Size of inner gaps                */
static const unsigned int ogappx    = 0; /* Size of outer gaps                */
static const unsigned int snap      = 32;/* Snap pixel                        */
static const unsigned int borderpx  = 1; /* Border pixel of windows           */
static const char *fonts[]          = { "FreeMono:size=12", /* Primary        */
                                        "FreeSerif:size=12", /* Secondary     */
                                        "FontAwesome:size=10" }; /* Iconic    */
/*  DWM color scheme                                                          */
static const char barselfg[]        = "#282828"; /* Bar foreground selected   */
static const char barselbg[]        = "#d65d0e"; /* Bar background selected   */
static const char tlbrdsel[]        = "#a89984"; /* Tiled border selected     */
static const char flbrdsel[]        = "#a89984"; /* Floating border selected  */
static const char urbrdsel[]        = "#b8bb26"; /* Urgent border selected    */
static const char barnrmfg[]        = "#a89984"; /* Bar foreground normal     */
static const char barnrmbg[]        = "#282828"; /* Bar background normal     */
static const char tlbrdnrm[]        = "#928374"; /* Tiled border normal       */
static const char flbrdnrm[]        = "#928374"; /* Floating border normal    */
static const char urbrdnrm[]        = "#b8bb26"; /* Urgent border normal      */
static const char *colors[][5]      = {
/*  Scheme           Foreground, Background, TileBorder, FltBorder, UrgBorder */
    [SchemeSel]  = { barselfg,   barselbg,   tlbrdsel,   flbrdsel,  urbrdsel  },
    [SchemeNorm] = { barnrmfg,   barnrmbg,   tlbrdnrm,   flbrdnrm,  urbrdnrm  },
};
/*  DWM Alpha scheme                                                          */
static const unsigned int barfgA           = 0xffU; /* Opaque foreground      */
static const unsigned int barbgA           = 0xd0;  /* Transparent background */
static const unsigned int tlbrdA           = 0xffU; /* Opaque tiled border    */
static const unsigned int flbrdA           = 0xffU; /* Opaque floating border */
static const unsigned int urbrdA           = 0xffU; /* Opaque urgent border   */
static const unsigned int alphas[][5]      = {
/*  Scheme           Foreground, Background, TileBorder, FltBorder, UrgBorder */
    [SchemeSel]  = { barfgA,     barbgA,     tlbrdA,     flbrdA,    urbrdA    },
    [SchemeNorm] = { barfgA,     barbgA,     tlbrdA,     flbrdA,    urbrdA    },
};
/*  DWM icons                                                                 */
static const char *mscsym[]                  = { "\uF011", "\uF11C", "\uF110" };
static const char *lcksym[]                  = { "\uF13E", "\uF023", "\uF23E" };
static const char *vntsym[]                  = { "\uF2D0", "\uF2D2", "\uF3C1" };  
static const char *wnfsym[]                  = { "\uF245", "\uF0E7", "\uF3C1" };
static const char *lngsym[]                  = { "EN", "KA", "AR", "DE", "RU" };
static const char *atdsym[]                  = { "\uF102", "\uF106", "\uF0D8",
                                                 "\uF107", "\uF103", "\uF0D7" };
/*  DWM tags                                                                  */
static const char *tags[]                    = { "\uF406", "\uF269", "\uF09B",
                                                 "\uF04B", "\uF03D", "\uF130",
                                                 "\uF0D0", "\uF1B6", "\uF085" };
static const char *tagsalt[]                 = { "1", "2", "3", "4", "5", "6",
                                                                "7", "8", "9" };
/*  DWM layout settings                                                       */
static const int dirs[3]         = { DirHor, DirVer, DirVer }; /* Tiling dirs */
static const float facts[3]      = { 1.1,    1.1,    1.1 }; /* Tiling facts   */
static const int nmaster         = 1; /* Number of clients in master area     */
static const int resizehints     = 0; /* 1 means size hints in tiled resizals */
static const int decorhints      = 1; /* 1 means respect decoration hints     */
static const int attachdirection = 4; /* 0 top, 1 above, 2 on top of stack,
                                         3 below, 4 bottom, 5 below I master  */
/*  DWM layout symbols                                                        */
static const Layout layouts[] = {
/*  Symbol        Layout                                                      */
    { "[+]",      tile },    /* Tiling layout with xtile behaviors patched in */
    { "[*]",      NULL },    /* No layout function means floating behavior    */
    { "[M]",      monocle }, /* Classic monocle layout                        */
    { NULL,       NULL },
};
/*=====================================St=====================================*/
static const char *termcmd[]           = { "st", NULL };
static const char *dwmpwr[]            = { "dwmpwr", NULL };
static const char *dwmusr[]            = { "st", "dwmusr", NULL };
static const char *dwmman[]            = { "st", "man", "dwm", NULL };
static const char *dmnman[]            = { "st", "man", "dmenu", NULL };
static const char *xsrman[]            = { "st", "man", "xsetroot", NULL };
static const char *xkbman[]            = { "st", "man", "setxkbmap", NULL };
static const char *pondwn[]            = { "dwmponymix", "down", NULL };
static const char *ponvup[]            = { "dwmponymix", "up", NULL };
static const char *pontog[]            = { "dwmponymix", NULL };
/*===================================Dmenu====================================*/
static const char dmenuprompt[]        = "Launch";                              
static char dmenumon[2]                = "0"; /* manipulated in spawn         */
static const char *dmenucmd[]          = { "dmenu_run", "-m", dmenumon, 
                                                      "-p", dmenuprompt, NULL };
/*===================================Extra====================================*/
/*  Helper for spawning shell commands in the pre dwm-5.0 fashion             */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
/*==================================Scratch===================================*/
const char *spcmd1[]                   = {"st", "-n", "Spad1", NULL };
const char *spcmd2[]                   = {"st", "-n", "Spad2", NULL };
const char *spcmd3[]                   = {"keepassxc", NULL };
static Sp scratchpads[]                = {
/*      name                           command                                */
	{"Spad1",                      spcmd1},
	{"Spad2",                      spcmd2},
	{"keepassxc",                  spcmd3},
};
/*==================================AutoStart=================================*/
static const char *const autostart[]   = {
	"dwmstatus", NULL,
	NULL /* terminate */
};
/*===================================Signals==================================*/
/*  Signum must be greater than 0                                             */
/*  Trigger signals using `xsetroot -name "fsignal:<signum>"                  */
static Signal signals[]                = {
	/* signum                      function                      argument */
	{ 99,                          quit,                              {0} },
};
/*====================================Keys====================================*/
/*  DWM macros                                                                */
#define MODKEY Mod4Mask
#define CTRL ControlMask
#define SHIFT ShiftMask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define TILEKEYS(MOD,G,M,S) \
	{ MOD, 27, setdirs,  {.v = (int[])  { INC(G * +1),   INC(M * +1),   INC(S * +1)   } } }, \
	{ MOD, 43, setfacts, {.v = (float[]){ INC(G * -0.1), INC(M * -0.1), INC(S * -0.1) } } }, \
	{ MOD, 46, setfacts, {.v = (float[]){ INC(G * +0.1), INC(M * +0.1), INC(S * +0.1) } } },
#define STACKKEYS(MOD,ACTION) \
	{ MOD, 45,     ACTION##stack, {.i = INC(+1) } }, \
	{ MOD, 44,     ACTION##stack, {.i = INC(-1) } }, \
	{ MOD, 24,     ACTION##stack, {.i = PREVSEL } }, \
	{ MOD, 25,     ACTION##stack, {.i = 0 } }, \
	{ MOD, 38,     ACTION##stack, {.i = 1 } }, \
	{ MOD, 52,     ACTION##stack, {.i = 2 } }, \
	{ MOD, 53,     ACTION##stack, {.i = -1 } },
/*  DWM keys and definitions                                                      */
static Key keys[] = {
	/* modifier                     key        function              argument */
	{ MODKEY,                       36,        spawn,         {.v = termcmd } },
	{ MODKEY|ShiftMask,             36,        togglescratch,      {.ui = 0 } },
	{ MODKEY|ControlMask,           36,        togglescratch,      {.ui = 1 } },
	{ MODKEY|ShiftMask|ControlMask, 36,        togglescratch,      {.ui = 2 } },
	{ MODKEY,                       22,        spawn,        {.v = dmenucmd } },
	{ MODKEY,                       49,        setlayout,                 {0} },
	{ MODKEY|ShiftMask,             49,        cyclelayout,        {.i = +1 } },
	{ MODKEY|ControlMask,           49,        cyclelayout,        {.i = -1 } },
	{ MODKEY|ShiftMask,             57,        incnmaster,         {.i = +1 } },
	{ MODKEY|ControlMask,           57,        incnmaster,         {.i = -1 } },
	{ MODKEY|ShiftMask,             40,        toggleattachdir,    {.i = +1 } },
	{ MODKEY|ControlMask,           40,        toggleattachdir,    {.i = -1 } },
	{ MODKEY|ShiftMask|ControlMask, 40,        toggleattachdir,           {0} },
	{ MODKEY,                       54,        togglewarp,                {0} },
	{ MODKEY,                       55,        toggleviewontag,           {0} },
	{ MODKEY,                       41,        setfullscreenlayout,       {0} },
	{ MODKEY|ShiftMask,             41,        setfullscreennative,       {0} },
	{ MODKEY|ControlMask,           41,        setfullscreenforced,       {0} },
	{ MODKEY|ShiftMask|ControlMask, 41,        toggleisfakefs,            {0} },
	{ MODKEY,                       65,        togglefloating,            {0} },
	{ MODKEY|ShiftMask|ControlMask, 65,        toggleispermanent,         {0} },
	{ MODKEY|ShiftMask,             31,        setigaps,           {.i = +2 } },
	{ MODKEY|ControlMask,           31,        setigaps,           {.i = -2 } },
	{ MODKEY|ShiftMask|ControlMask, 31,        setigaps,           {.i = 0  } },
	{ MODKEY|ShiftMask,             32,        setogaps,           {.i = +2 } },
	{ MODKEY|ControlMask,           32,        setogaps,           {.i = -2 } },
	{ MODKEY|ShiftMask|ControlMask, 32,        setogaps,           {.i = 0  } },
	{ MODKEY,                       32,        togglegapsforone,          {0} },
	{ MODKEY,                       31,        togglegapsformonocle,      {0} },
	{ MODKEY|ShiftMask,             33,        setborderpx,        {.i = +1 } },
	{ MODKEY|ControlMask,           33,        setborderpx,        {.i = -1 } },
	{ MODKEY|ShiftMask|ControlMask, 33,        setborderpx,         {.i = 0 } },
	{ MODKEY,                       56,        togglebar,           {.i = 0 } },
	{ MODKEY|ShiftMask,             56,        togglebar,           {.i = 1 } },
	{ MODKEY|ControlMask,           56,        togglebar,           {.i = 2 } },
	{ MODKEY|ShiftMask|ControlMask, 56,        togglebar,          {.i = -1 } },
	{ MODKEY,                       28,        togglealttag,              {0} },
	{ MODKEY|ShiftMask,             28,        togglehidevactags,         {0} },
	{ MODKEY,                       59,        focusmon,           {.i = -1 } },
	{ MODKEY,                       60,        focusmon,           {.i = +1 } },
	{ MODKEY|ShiftMask,             59,        tagmon,             {.i = -1 } },
	{ MODKEY|ShiftMask,             60,        tagmon,             {.i = +1 } },
	{ MODKEY,                       23,        view,                      {0} },
	{ MODKEY|ShiftMask,             23,        shiftview,          {.i = +1 } },
	{ MODKEY|ControlMask,           23,        shiftview,          {.i = -1 } },
	{ MODKEY,                       19,        view,              {.ui = ~0 } },
	{ MODKEY|ShiftMask,             19,        tag,               {.ui = ~0 } },
	TAGKEYS(                        10,                                    0)
	TAGKEYS(                        11,                                    1)
	TAGKEYS(                        12,                                    2)
	TAGKEYS(                        13,                                    3)
	TAGKEYS(                        14,                                    4)
	TAGKEYS(                        15,                                    5)
	TAGKEYS(                        16,                                    6)
	TAGKEYS(                        17,                                    7)
	TAGKEYS(                        18,                                    8)
	STACKKEYS(MODKEY,                                                  focus)
	STACKKEYS(MODKEY|ShiftMask,                                         push)
	TILEKEYS(MODKEY,                                                 1, 0, 0)
	TILEKEYS(MODKEY|ShiftMask,                                       0, 1, 0)
	TILEKEYS(MODKEY|ControlMask,                                     0, 0, 1)
	TILEKEYS(MODKEY|ShiftMask|ControlMask,                           1, 1, 1)
	{ MODKEY,                       110,       togglekeys,                {0} },
	{ MODKEY,                       9,         killclient,                {0} },
	{ MODKEY|ShiftMask,             9,         killunsel,                 {0} },
	{ MODKEY|ControlMask,           9,         spawn,          {.v = dwmpwr } },
	{ MODKEY|ShiftMask|ControlMask, 9,         quit,                      {0} },
	{ MODKEY,                       67,        spawn,          {.v = dwmman } },

	{ MODKEY,                       69,        spawn,          {.v = pontog } },
	{ MODKEY,                       74,        spawn,          {.v = pondwn } },
	{ MODKEY,                       75,        spawn,          {.v = ponvup } },
};
static Key altkeys[] = {
	/* modifier                     key        function              argument */
	{ MODKEY,                       110,       togglekeys,                {0} },
	{ MODKEY|ShiftMask|ControlMask, 9,         quit,                      {0} },
};
/*===================================Buttons==================================*/
/*  DWM button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkUser,              0,              Button1,        spawn,          {.v = termcmd } },
	{ ClkUser,              0,              Button3,        spawn,          {.v = dwmusr } },
	{ ClkWinTitle,          0,              Button1,        togglescratch,  {.ui = 0 } },
	{ ClkWinTitle,          0,              Button3,        spawn,          {.v = dmenucmd } },
	{ ClkLtSymbol,          0,              Button2,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button1,        cyclelayout,    {.i = +1 } },
	{ ClkLtSymbol,          0,              Button3,        cyclelayout,    {.i = -1 } },
	{ ClkPower,             0,              Button1,        spawn,          {.v = dwmpwr } },
	{ ClkLock,              0,              Button1,        togglekeys,     {0} },
	{ ClkViewT,             0,              Button1,        toggleviewontag,{0} },
	{ ClkWarpP,             0,              Button1,        togglewarp,     {0} },
	{ ClkKeyboard,          0,              Button1,        spawn,          {.v = dwmman } },
	{ ClkKeyboard,          0,              Button3,        spawn,          {.v = dmnman } },
	{ ClkLanguage,          0,              Button1,        spawn,          {.v = xkbman } },
	{ ClkAttachDir,         0,              Button1,        toggleattachdir,{.i = +1 } },
	{ ClkAttachDir,         0,              Button3,        toggleattachdir,{.i = -1 } },
	{ ClkAttachDir,         0,              Button2,        toggleattachdir,{0} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        zoom,           {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkStatusText,        MODKEY,         Button1,        spawn,          {.v = xsrman } },
};
/*===================================Rules====================================*/
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class           instance    title                tags mask     switchtotag   iscentered   isfloating   isfreesize   isfakefullscreen   isterminal   noswallow   ispermanent   monitor */
	{ NULL,            NULL,       "Event Tester",      0,            0,            0,           1,           1,           0,                 0,           1,          0,            -1      },
	{ "st",            NULL,       NULL,                0,            0,            0,           0,           0,           0,                 1,           0,          0,            -1      },
	{ NULL,            "Spad1",    NULL,                SPTAG(0),     0,            1,           1,           0,           0,                 0,           0,          0,            -1      },
	{ NULL,            "Spad2",    NULL,                SPTAG(1),     0,            1,           1,           0,           0,                 0,           0,          0,            -1      },
	{ NULL,            "keepassxc",NULL,                SPTAG(2),     0,            1,           1,           0,           0,                 0,           0,          0,            -1      },
	{ "firefox",       NULL,       NULL,                1 << 1,       0,            0,           0,           0,           0,                 0,           1,          0,            -1      },
	{ "code-oss",      NULL,       NULL,                1 << 2,       0,            0,           0,           0,           0,                 0,           0,          0,            -1      },
	{ "Gimp",          NULL,       NULL,                1 << 6,       0,            0,           1,           1,           0,                 0,           1,          0,            -1      },
	{ "Steam",         NULL,       NULL,                1 << 7,       0,            0,           1,           1,           0,                 0,           1,          1,            -1      },
};
