type t('a);
let fromArray: (array('a), ('a, 'a) => int) => t('a);
let make: (('a, 'a) => int) => t('a);
let push: (t('a), 'a) => unit;
let peek: t('a) => option('a);
let peekExn: t('a) => 'a;
let pop: t('a) => option('a);
let popExn: t('a) => 'a;
let size: t('a) => int;