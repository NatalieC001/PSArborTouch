//
//  ATGeometry.h
//  PSArborTouch
//
//  Created by Ed Preston on 5/09/11.
//  Copyright 2011 Preston Software. All rights reserved.
//
//  particle system- or physics-related datatypes


#import <Foundation/Foundation.h>


#define ARC4RANDOM_MAX      0x100000000
#define RANDOM_0_1          ((CGFloat)arc4random()/(CGFloat)ARC4RANDOM_MAX)


// TODO: Document

static inline BOOL CGPointExploded(const CGPoint a)
{
    // Not safe for some math optimization flags
    return( isnan(a.x) || isnan(a.y) );
}

// TODO: Document

static inline CGPoint CGPointAdd(const CGPoint a, const CGPoint b)
{
    CGPoint r = { .x = a.x + b.x, .y = a.y + b.y };
    return(r);
}

// TODO: Document

static inline CGPoint CGPointSubtract(const CGPoint p1, const CGPoint p2)
{
    return(CGPointMake(p1.x - p2.x, p1.y - p2.y));
}

// TODO: Document

static inline CGPoint CGPointMultiply(const CGPoint a, const CGPoint b)
{
    CGPoint r = { .x = a.x * b.x, .y = a.y * b.y };
    return(r);
}

// TODO: Document

static inline CGPoint CGPointMultiplyFloat(const CGPoint a, const CGFloat n)
{
    CGPoint r = { .x = a.x * n, .y = a.y * n };
    return(r);
}

// TODO: Document

static inline CGPoint CGPointDivideFloat(const CGPoint a, const CGFloat n)
{
    //    NSParameterAssert( n > 0);
    
    CGPoint r = { .x = a.x / n, .y = a.y / n };
    return(r);
}

// TODO: Document

//static inline CGFloat distance(CGPoint start, CGPoint finish)
//{
//    CGFloat theDistance = sqrtf(powf( (start.x - finish.x), 2.0f) + powf( (start.y - finish.y), 2.0f));
//    return(theDistance);
//}

// TODO: Document

static inline CGFloat magnitude(const CGPoint point)
{
    CGFloat theMagnitude = sqrt( (point.x * point.x) + (point.y * point.y) );
    return(theMagnitude);
}

// TODO: Document

static inline CGPoint CGPointNormal(const CGPoint a)
{
    CGPoint r = { .x = a.x, .y = -a.y };
    return(r);
}

// TODO: Document

static inline CGPoint CGPointNormalize(const CGPoint a)
{    
    CGPoint r = CGPointDivideFloat(a, magnitude(a));
    return(r);
}

// TODO: Document

static inline CGPoint CGPointRandom(const CGFloat radius)
{
    CGFloat targetRadius = (radius > 0) ? radius : 5;
    CGPoint r = { .x = 2*targetRadius * (RANDOM_0_1 - 0.5), .y = 2*targetRadius* (RANDOM_0_1 - 0.5) };
    return(r);
}

// TODO: Document

static inline CGPoint CGPointNearPoint(const CGPoint center_pt, const CGFloat radius)
{
    CGFloat targetRadius = (radius > 0.0f) ? radius : 0.0f;
    CGFloat x = center_pt.x;
    CGFloat y = center_pt.y;
    CGFloat d = targetRadius * 2;
    
    CGPoint r = { .x = x - targetRadius + RANDOM_0_1 * d, .y = y - targetRadius + RANDOM_0_1 * d};
    return(r);
}