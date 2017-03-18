//
// Created by shahab on 05/11/2016.
//

#ifndef TEMPLATEEXPERIMENT_ROLE_H
#define TEMPLATEEXPERIMENT_ROLE_H


class RoleBase {
    friend class Relationship;

    int const maxPerformers;
    int currentPerformers = 0;

    bool isPerformerNeeded();

    void addPerformer();

protected:
    RoleBase(int maxPerformers);
};

template<int role>
class RelationshipRole : public RoleBase {
public:
    RelationshipRole<role>(int maxPerformers) : RoleBase(maxPerformers) {}
};


#endif //TEMPLATEEXPERIMENT_ROLE_H
