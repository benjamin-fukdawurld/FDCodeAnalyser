#ifndef ANALYSER_MACROS_H
#define ANALYSER_MACROS_H

#define ReflectNamespace(...) namespace __attribute__((annotate("reflect-namespace;" #__VA_ARGS__)))
#define ReflectUnion(...) union __attribute__((annotate("reflect-union;" #__VA_ARGS__)))
#define ReflectEnum(...) enum __attribute__((annotate("reflect-enum;" #__VA_ARGS__)))
#define ReflectClass(...) class __attribute__((annotate("reflect-class;" #__VA_ARGS__)))
#define ReflectStruct(...) struct __attribute__((annotate("reflect-struct;" #__VA_ARGS__)))
#define ReflectVariable(...) __attribute__((annotate("reflect-variable;" #__VA_ARGS__)))
#define ReflectMember(...) __attribute__((annotate("reflect-member;" #__VA_ARGS__)))
#define ReflectProperty(...) __attribute__((annotate("reflect-property;" #__VA_ARGS__)))
#define ReflectFunction(...) __attribute__((annotate("reflect-function;" #__VA_ARGS__)))

#endif // ANALYSER_MACROS_H