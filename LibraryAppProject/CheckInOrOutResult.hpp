#pragma once

//Cases for check in or out results
enum class CheckInOrOutResult
{
    Success,
    BookNotFound,
    CheckoutAlready,
    AlreadyCheckedIn,
    Failed
};