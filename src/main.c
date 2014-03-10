#include <pebble.h>
#include <stdlib.h>
#include <stdio.h>

Window *window;
TextLayer *text_layer;

char* initialblow[] = {"Away I say", "Bathe thyself", "Be not deaf", "Behold thy mirror", "Beware my sting", "Clean thine ears", "Drink up eisel", "Eat a crododile", "Eat my knickers", "Fie upon thee", "Forsooth say I", "Get thee gone", "Get thee hence", "Grow unsightly warts", "Hear me now", "Hear this pox alert", "I shall see thee hanged", "Kiss my codpiece", "Lead apes in hell", "Methinks you stink", "My finger in thine eye", "Phui, I say", "Remove thine horse hence", "Resign not thy day gig", "Sit thee on a spit", "Sorrow on thee", "Swim with leeches", "Thou dost intrude", "Thy mother wears armor", "Trip on thy sword", "Tune thy lute", "Why, how now putz", "Wipe thy ugly face"};
char* secondblow[] = {"artless", "bawdy", "beslubbering", "bootless", "cankerous", "churlish", "cockered", "clouted", "craven", "currish", "dankish", "dissembling", "droning", "errant", "fawning", "fobbing", "fool-born", "froward", "frothy", "gleeking", "goatish", "gorbellied", "ill-nurtured", "impertinent", "incestuous", "incurable", "infectious", "jarring", "loggerheaded", "lumpish", "loutish", "mammering", "mangled", "mewling", "paunchy", "pribbling", "puking", "puny", "qualling", "rank", "reeky", "roguish", "rump-fed", "ruttish", "saucy", "spleeny", "spongy", "surly", "tardy-gaited", "tottering", "unmuzzled", "vain", "venomed", "warped", "wayward", "weedy", "whoreson", "wretched", "yeasty"};
char* thirdblow[] = {"addlepated", "base-court", "bat-fowling", "beef-witted", "beetle-headed", "boil-brained", "clapper-clawed", "clay-brained", "codpiece-sniffing", "common-kissing", "crook-pated", "dismal-dreaming", "dizzy-eyed", "doghearted", "dread-bolted", "earth-vexing", "elf-skinned", "fat-kidneyed", "fen-sucked", "flap-mouthed", "fly-bitten", "folly-fallen", "fool-born", "foul-practicing", "full-gorged", "guts-griping", "half-faced", "hasty-witted", "hedge-born", "hell-hated", "idle-headed", "ill-breeding", "ill-nurtured", "knotty-pated", "mad-brained", "milk-livered", "motley-minded", "onion-eyed", "plume-plucked", "pottle-deep", "pox-marked", "reeling-ripe", "rough-hewn", "rude-growing", "rump-fed", "shard-borne", "sheep-biting", "spur-galled", "swag-bellied", "tardy-gaited", "tickle-brained", "toad-spotted", "unchin-snouted", "weather-bitten"};
char* finalblow[] = {"apple-john", "baggage", "barnacle", "bladder", "boar-pig", "bugbear", "bum-bailey", "canker-blossom", "clack-dish", "clotpole", "coxcomb", "codpiece", "death-token", "dewberry", "dotard", "flap-dragon", "flax-wench", "flea", "flirt-gill", "foot-licker", "fustilarian", "giglet", "gudgeon", "haggard", "harpy", "hedge-pig", "horn-beast", "hugger-mugger", "jolthead", "knave", "lewdster", "lout", "maggot-pie", "malt-worm", "mammet", "measle", "minnow", "miscreant", "moldwarp", "mumble-news", "nit", "nut-hook", "pigeon-egg", "pignut", "pumpion", "puttock", "ratsbane", "rudesby", "scut", "skainsmate", "strumpet", "varlot", "vassal", "wagtail", "water-fly", "whey-face", "winter-cricket"};

int length1 = sizeof(initialblow)/sizeof(*initialblow);
int length2 = sizeof(secondblow)/sizeof(*secondblow);
int length3 = sizeof(thirdblow)/sizeof(*thirdblow);
int length4 = sizeof(finalblow)/sizeof(*finalblow);

char* genInsult()
{
	char out[256];
	snprintf(out, 256, "%s, thou %s %s %s.", initialblow[rand() % length1], secondblow[rand() % length2], thirdblow[rand() % length3], finalblow[rand() % length4]);
	
	// Really hacky way of doing this... 
    char* result = malloc(strlen(out) + 1);
    strcpy(result, out);
    return result;	
}

static void select_click_handler(ClickRecognizerRef recognizer, void *context)
{
	char* insult = genInsult();
	
	text_layer_set_text(text_layer, insult);
	
	free(insult);
}

static void click_config_provider(void *context)
{
	window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
	window_single_click_subscribe(BUTTON_ID_UP, select_click_handler);
	window_single_click_subscribe(BUTTON_ID_DOWN, select_click_handler);
}

static void window_load(Window *window)
{
	Layer *window_layer = window_get_root_layer(window);
	GRect bounds = layer_get_bounds(window_layer);
	
	text_layer = text_layer_create((GRect) { .origin = { 0, 10 /*72*/ }, .size = { bounds.size.w, bounds.size.h } });
	text_layer_set_text(text_layer, "Press buttons for an insult!");
	text_layer_set_font(text_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
	
	text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);
	layer_add_child(window_layer, text_layer_get_layer(text_layer));
}
 
static void window_unload(Window *window)
{
	text_layer_destroy(text_layer);
}

void handle_init(void)
{
	window = window_create();
	window_set_click_config_provider(window, click_config_provider);
	window_set_window_handlers(window, (WindowHandlers) {
		.load = window_load,
		.unload = window_unload,
	});
	const bool animated = true;
	window_stack_push(window, animated);	
}

void handle_deinit(void)
{
	  text_layer_destroy(text_layer);
	  window_destroy(window);
}

int main(void)
{
	  handle_init();
	  app_event_loop();
	  handle_deinit();
}
