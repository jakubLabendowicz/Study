var light = new Theme("Jasny");
light.add("--mainBackgroundColor", "#ffffff");

light.add("--cardHeaderColor", "#000000");
light.add("--cardDescriptionColor", "#616161");
light.add("--cardDescriptionHoverColor", "#000000");
light.add("--cardTextColor", "#616161");
light.add("--cardTextHoverColor", "#000000");
light.add("--cardBoxColor", "#d2d2d2");
light.add("--cardComponentshadowColor", "#00000029");

light.add("--CVBackgroundColor", "#fafafa");
light.add("--GHImage", "url('../graphics/GitHub-Mark-120px-plus.png')");
light.add("--QRImage", "url('../graphics/QRDark.png')");


// var dimmed = new Theme("Dimmed");
// dimmed.add("--mainBackgroundColor", "#ffffff");
// dimmed.add("--cardHeaderColor", "#000000");
// dimmed.add("--cardTextColor", "#616161");
// dimmed.add("--cardTextHoverColor", "#000000");
// dimmed.add("--projectShadowColor", "#00000029");
// dimmed.add("--CVBackgroundColor", "#fafafa");
//dimmed.add("--GHImage", "url('../graphics/GitHub-Mark-120px-plus.png')");
//dimmed.add("--QRImage", "url('../graphics/QRLight.png')");

var dark = new Theme("Ciemny");
dark.add("--mainBackgroundColor", "#101010");

dark.add("--cardHeaderColor", "#ffffff");
dark.add("--cardDescriptionColor", "#eeeeee");
dark.add("--cardDescriptionHoverColor", "#ffffff");
dark.add("--cardTextColor", "#eeeeee");
dark.add("--cardTextHoverColor", "#ffffff");
dark.add("--cardBoxColor", "#212121");
dark.add("--cardComponentshadowColor", "#000000");

dark.add("--CVBackgroundColor", "#000000");
dark.add("--GHImage", "url('../graphics/GitHub-Mark-Light-64px.png')");
dark.add("--QRImage", "url('../graphics/QRLight.png')");

var themeController = new ThemeController("themeController");
themeController.addTheme(light);
// themeController.addTheme(dimmed);
themeController.addTheme(dark);

themeController.addButton("themebutton");
// themeController.addButton("themebutton2");
themeController.addStatus("themebutton");

// document.getElementById("defaultThemeSetter2").addEventListener('click',function () {themeController.synchronizeLocalTheme()});

themeController.run();
