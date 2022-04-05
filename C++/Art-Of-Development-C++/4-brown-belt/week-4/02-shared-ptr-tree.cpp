#include "tools.h"

class Expression
{
    public:
        virtual ~Expression() = default;

        virtual int Evaluate() const = 0;

        virtual std::string ToString() const = 0;
};

using ExpressionPtr = std::shared_ptr<Expression>;

class ValueExpr : public Expression
{
    public:
        ValueExpr(int value) : value_(value)
        {
        }

        int Evaluate() const override
        {
            return value_;
        }
        std::string ToString() const override
        {
            return std::to_string(value_);
        }

    private:
        int value_;
};


class BinaryExpr : public Expression
{
    public:
        BinaryExpr(ExpressionPtr left, ExpressionPtr right) :
                left_(move(left)),
                right_(move(right))
                {
                }

        std::string ToString() const final
        {
            std::ostringstream result;
            result << '(' << left_->ToString() << ')'
                          << GetSymbol()
                          << '(' << right_->ToString() << ')';
            return result.str();
        }

        int Evaluate() const final
        {
            return EvaluateOnValues(left_->Evaluate(), right_->Evaluate());
        }

    private:
        virtual char GetSymbol() const = 0;
        virtual int EvaluateOnValues(int l, int r) const = 0;

        ExpressionPtr left_;
        ExpressionPtr right_;
};


class ProductExpr : public BinaryExpr
{
    public:
        ProductExpr(ExpressionPtr left, ExpressionPtr right) :
                BinaryExpr(move(left), move(right))
                {
                }

    private:
        char GetSymbol() const override
        {
            return '*';
        }

        int EvaluateOnValues(int left, int right) const override
        {
            return left * right;
        }
};


class SumExpr : public BinaryExpr
{
    public:
        using BinaryExpr::BinaryExpr;

    private:
        char GetSymbol() const override
        {
            return '+';
        }

        int EvaluateOnValues(int left, int right) const override
        {
            return left + right;
        }
};


ExpressionPtr Value(int value)
{
    return std::make_shared<ValueExpr>(value);
}

ExpressionPtr Sum(ExpressionPtr left, ExpressionPtr right)
{
    return std::make_shared<SumExpr>(move(left), move(right));
}

ExpressionPtr Product(ExpressionPtr left, ExpressionPtr right)
{
    return std::make_shared<ProductExpr>(move(left), move(right));
}

void Print(const Expression* e)
{
    if (!e)
    {
        std::cout << "Null expression provided" << std::endl;
        return;
    }

    std::cout << e->ToString() << " = " << e->Evaluate() << std::endl;
}

int main()
{
    ExpressionPtr e1 = Product(Value(2), Sum(Value(3), Value(4)));
    Print(e1.get());

    ExpressionPtr e2 = Sum(e1, Value(5));
    Print(e2.get());

    Print(e1.get());

    ExpressionPtr e3 = Sum(e1, e2);
    Print(e3.get());

    return 0;
}
