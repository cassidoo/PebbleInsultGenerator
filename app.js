simply.title('Insult Generator');
simply.subtitle('');
simply.scrollable(true);

var initialblow = ['Away I say', 'Bathe thyself', 'Be not deaf', 'Behold thy mirror', 'Beware my sting', 'Clean thine ears', 'Drink up eisel', 'Eat a crododile', 'Eat my knickers', 'Fie upon thee', 'Forsooth say I', 'Get thee gone', 'Get thee hence', 'Grow unsightly warts', 'Hear me now', 'Hear this pox alert', 'I shall see thee hanged', 'Kiss my codpiece', 'Lead apes in hell', 'Methinks you stinks', 'My finger in thine eye', 'Phui, I say', 'Remove thine ass hence', 'Resign not thy day gig', 'Sit thee on a spit', 'Sorrow on thee', 'Swim with leeches', 'Thou dost intrude', 'Thy mother wears armor', 'Trip on thy sword', 'Tune thy lute', 'Why, how now putz', 'Wipe thy ugly face'];

var secondblow = ['artless', 'bawdy', 'beslubbering', 'bootless', 'cankerous', 'churlish', 'cockered', 'clouted', 'craven', 'currish', 'dankish', 'dissembling', 'droning', 'errant', 'fawning', 'fobbing', 'fool-born', 'froward', 'frothy', 'gleeking', 'goatish', 'gorbellied', 'ill-nurtured', 'impertinent', 'incestuous', 'incurable', 'infectious', 'jarring', 'loggerheaded', 'lumpish', 'loutish', 'mammering', 'mangled', 'mewling', 'paunchy', 'pribbling', 'puking', 'puny', 'qualling', 'rank', 'reeky', 'roguish', 'rump-fed', 'ruttish', 'saucy', 'spleeny', 'spongy', 'surly', 'tardy-gaited', 'tottering', 'unmuzzled', 'vain', 'venomed', 'warped', 'wayward', 'weedy', 'whoreson', 'wretched', 'yeasty'];

var thirdblow = ['addlepated', 'base-court', 'bat-fowling', 'beef-witted', 'beetle-headed', 'boil-brained', 'clapper-clawed', 'clay-brained', 'codpiece-sniffing', 'common-kissing', 'crook-pated', 'dismal-dreaming', 'dizzy-eyed', 'doghearted', 'dread-bolted', 'earth-vexing', 'elf-skinned', 'fat-kidneyed', 'fen-sucked', 'flap-mouthed', 'fly-bitten', 'folly-fallen', 'fool-born', 'foul-practicing', 'full-gorged', 'guts-griping', 'half-faced', 'hasty-witted', 'hedge-born', 'hell-hated', 'idle-headed', 'ill-breeding', 'ill-nurtured', 'knotty-pated', 'mad-brained', 'milk-livered', 'motley-minded', 'onion-eyed', 'plume-plucked', 'pottle-deep', 'pox-marked', 'reeling-ripe', 'rough-hewn', 'rude-growing', 'rump-fed', 'shard-borne', 'sheep-biting', 'spur-galled', 'swag-bellied', 'tardy-gaited', 'tickle-brained', 'toad-spotted', 'unchin-snouted', 'weather-bitten'];

var finalblow = ['apple-john', 'baggage', 'barnacle', 'bladder', 'boar-pig', 'bugbear', 'bum-bailey', 'canker-blossom', 'clack-dish', 'clotpole', 'coxcomb', 'codpiece', 'death-token', 'dewberry', 'dotard', 'flap-dragon', 'flax-wench', 'flea', 'flirt-gill', 'foot-licker', 'fustilarian', 'giglet', 'gudgeon', 'haggard', 'harpy', 'hedge-pig', 'horn-beast', 'hugger-mugger', 'jolthead', 'knave', 'lewdster', 'lout', 'maggot-pie', 'malt-worm', 'mammet', 'measle', 'minnow', 'miscreant', 'moldwarp', 'mumble-news', 'nit', 'nut-hook', 'pigeon-egg', 'pignut', 'pumpion', 'puttock', 'ratsbane', 'rudesby', 'scut', 'skainsmate', 'strumpet', 'varlot', 'vassal', 'wagtail', 'water-fly', 'whey-face', 'winter-cricket'];

function randomCombo()
{
    return initialblow[Math.floor(Math.random() * (initialblow.length))] + ", thou " + secondblow[Math.floor(Math.random() * (secondblow.length))] + " " + thirdblow[Math.floor(Math.random() * (thirdblow.length))] + " " + finalblow[Math.floor(Math.random() * (finalblow.length))] + ".";
}

//Commented sections are me trying to figure out how to save multiple insults.  We'll figure this out later.

//var previous = localStorage.getItem('previous') || 0;

simply.on('singleClick', function(e)
{
    if(e.button != 'up' && e.button != 'down')
    {
        var insult = randomCombo();
        simply.body(insult, true);
    }
    /*if (e.button === 'down') {
     simply.subtitle(previous);
     }

     localStorage.setItem('previous', insult);*/

}); 